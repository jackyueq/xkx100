s// tuwu.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��������"
int perform(object me, object target)
{
	int skill;
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "jinshe zhui" ||
		weapon->query("ownmake") == 1)
		return notify_fail("��û�ý���׶������ʹ�þ��У�\n");

	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if (me->query_temp("jinshe/tuwu"))
		return notify_fail("����õĽ�������û�����žͳ��С�\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

	skill = me->query_skill(bskill, 1);
	me->add("neili", -200);

	if (random(me->query_skill("force"))>target->query_skill("force")/2 ||
	    random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", 200,me);
		message_combatd(
HIY "ֻ��һ����ɨҶ��������У�$N"HIY"���е�"YEL"����׶"HIY"������Ŀ�Ĺ�â����ҫ��
$n��ð�𻨣�������������������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
		me->set_temp("jinshe/tuwu", 1);
		me->set_temp("noliving/cimu",1);
		target->set_temp("block_msg/all",1);
		call_out("tuwu_end", (int) skill/30, me, target);
	} else
	{
		me->start_busy(2);
		message_combatd("$Nʹ��һ�С�������������ϧ׶δ��������$n����
�Ȼ�����ʱ�ֽŴ��ҡ�\n", me, target);
	}
	return 1;
}
void tuwu_end(object me, object target)
{
//	target->enable_player();
  if (objectp(target))
  {
	  message_combatd("$N�����ָ��������������������ۡ�\n", target);
	  target->set_temp("block_msg/all", 0);
	  target->delete_temp("noliving");
  }
  if (objectp(me))
	me->delete_temp("jinshe/tuwu");
	return;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		���ͶԷ�����
		ʹ�Է���ʱʧ��

	����Ҫ��
		����׶��100��
		����300
HELP
	);
	return 1;
}

