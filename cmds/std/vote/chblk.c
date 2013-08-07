#include <vote.h> 
#include <ansi.h>

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason;   // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string *juror, *ips, my_id;

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("�㲻�ǿ���Ц�ɣ����ı�������Ȩ��\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_CHBLK))
  {
  	return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

  if( victim->query("chblk_on") ) 
  {
  	return notify_fail(victim->name()+"�Ľ�̸Ƶ���Ѿ��ǹرյ��ˡ�\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_CHBLK); 
  }
  
  my_id = query_ip_name(me);

  // don't allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	juror = victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 || wizardp(me)) 
  {
 	juror = victim->add("vote/juror", ({ my_id }) );
  } else
  {
  	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

/*  vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  
  vc = victim->add("vote/count", 1);

  df = (int)((vv - vc)/2);
  if (vv < 4) df = 4 - vc;*/
  ips = ("/cmds/std/vote")->valid_voters(me);
  vv = sizeof(ips);
  for (i=0;i<sizeof(juror);i++)
  {
  	if (member_array(juror[i],ips)==-1)
  	 vc = victim->add("vote/count",-1);
  }
  vc = victim->add("vote/count", 1);

  df = vv - vv/2 - vc;
  if (vv < 8) df = 4 - vc;

  if (df>0)
  {
	shout( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
			+"�Ľ�̸Ƶ��������"+sprintf("%d", df)+"Ʊ��\n" NOR);
	write( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
			+"�Ľ�̸Ƶ��������"+sprintf("%d", df)+"Ʊ��\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
	shout( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
			+"�Ľ�̸Ƶ����"+victim->name()+"�Ľ�̸Ƶ�����ر��ˣ�\n" NOR);
	write( HIG "�������"+me->name()+"ͶƱ�ر�" +victim->name()
			+"�Ľ�̸Ƶ����"+victim->name()+"�Ľ�̸Ƶ�����ر��ˣ�\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
	
	victim->set("chblk_on", 1);
	victim->delete("vote/juror");
		/* if (victim->query("chblk_rumor")) victim->delete("chblk_rumor");
	if (victim->query("chblk_chat")) victim->delete("chblk_chat"); */
  } 
  
  return 1;
}


