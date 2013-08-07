#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

string *blocks_name = ({
	"rumor",
	"chat",
	"xkx",
	"sing",
	"party",
});

int clear_vote(object victim);

int vote(object me, object victim)
{
  int reason;   // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string channel;
  string *juror, my_id ,*ips;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
  	return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

  if ( !victim->query("chblk_on"))
  	return notify_fail(victim->name()+"�Ľ�̸Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_UNCHBLK); 
  }
  
  //my_id = me->query("id");
  my_id = query_ip_name(me);

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 || wizardp(me)) 
  {
 	victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

/*  vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;  
  vc = victim->add("vote/count", 1);

  df = (int)((vv - vc)/2);
  if (vv < 4) df = 4 - vc;
*/
  ips = ("/cmds/std/vote")->valid_voters(me);
  vv = sizeof(ips);
  for (i=0;i<sizeof(juror);i++)
  {
  	if (member_array(juror[i],ips)==-1)
  	 vc = victim->add("vote/count",-1);
  }
  vc = victim->add("vote/count", 1);

  df = vv - vv*2/3 - vc;
  if (vv < 8) df = 4 - vc;
    
  my_name = me->name();
  if (me == victim) v_name = "�Լ�";
  	else  v_name = victim->name();

  if (df>0)
  {
	shout( HIG "�������"+my_name+"ͶƱ��" +v_name +"�Ľ�̸Ƶ��������"
			+sprintf("%d", df)+"Ʊ��\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name +"�Ľ�̸Ƶ��������"
			+sprintf("%d", df)+"Ʊ��\n" NOR);
    
	victim->apply_condition("vote_clear", 10);
			        
  } else 
  {
  	if (me != victim)
  	{
	shout( HIG "�������"+my_name+"ͶƱ��" +v_name+"�Ľ�̸Ƶ����"
		+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name+"�Ľ�̸Ƶ����"
		+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	} else 
	{
	shout( HIG "�������"+my_name+"ͶƱ���Լ��Ľ�̸Ƶ����"
		+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ���Լ��Ľ�̸Ƶ����"
		+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	}		
	
	victim->apply_condition("vote_clear", -10);
	victim->delete("vote/juror");
	victim->delete("chblk_on");
	for (i = 0;i < sizeof(blocks_name);i ++)
		victim->delete("chblk_" + blocks_name[i]);
} 
  
  return 1;
}


