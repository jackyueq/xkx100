// vote jail
#include <command.h> 
#include <vote.h> 
#include <ansi.h>
#define JAIL "/d/beijing/jail"

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string *juror, *ips , my_ip;
  object *inv;

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("�㲻�ǿ���Ц�ɣ����ı�������Ȩ��\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_CHBLK))
  {
  	return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

  if( base_name(environment(victim)) == JAIL) 
  {
  	return notify_fail(victim->name()+"�Ѿ��������̲��������ˡ�\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_CHBLK); 
  }
  
  my_ip = query_ip_name(me);

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	juror = victim->set("vote/juror", ({ my_ip }) );
  } else if( member_array(my_ip, juror) == -1 || wizardp(me))
  {
 	juror = victim->add("vote/juror", ({ my_ip }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }
  ips = ("/cmds/std/vote")->valid_voters(me);
  vv = sizeof(ips);
  for (i=0;i<sizeof(juror);i++)
  {
  	if (member_array(juror[i],ips)==-1)
  	 vc = victim->add("vote/count",-1);
  }
  vc = victim->add("vote/count", 1);

//  df = (int)((vv - vc)/2);
  df = vv - vv/2 - vc;
  if (vv < 8) df = 4 - vc;

  if (df>0)
  {
	shout( HIG "�������"+me->name()+"ͶƱ��" +victim->name()
			+"�����̲����Σ�����"+sprintf("%d", df)+"Ʊ��\n" NOR);
	write( HIG "�������"+me->name()+"ͶƱ��" +victim->name()
			+"�����̲����Σ�����"+sprintf("%d", df)+"Ʊ��\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
	shout( HIG "�������"+me->name()+"ͶƱ��" +victim->name()
			+"�����̲����Ρ�"+victim->name()+"�Ѿ��������̲������ˣ�\n" NOR);
	write( HIG "�������"+me->name()+"ͶƱ��" +victim->name()
			+"�����̲����Ρ�"+victim->name()+"�Ѿ��������̲������ˣ�\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
	victim->delete("vote/juror");
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(victim, inv[i]);
	}
//	victim->set("xkx_jail", 1);
	victim->move(JAIL);
  } 
  
  return 1;
}

