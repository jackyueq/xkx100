// tiaoyan.c ��������֮������ʽ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "������ʽ��"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage;
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
		(string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"������ʹ����"+PNAME+"��\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");
	if( target->query_temp("block_msg/all") )
		return notify_fail(target->name()+ "����ֻ��ͷ��Ӭ����ŵ������ɡ�\n");
	msg = HIG "$Nʹ����������֮������ʽ�������⼲��$n˫�ۡ�\n";

	me->start_busy(1);
	me->add("neili", -200);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		msg += "���$pֻ������ǰһ�ڣ�˫��һ���ʹ������ʲôҲ�������ˡ�\n" NOR;
		damage = (int)me->query_skill(bskill, 1)/5;
		if (!target->is_busy())
		target->start_busy((int)me->query_skill(bskill, 1) / 30 + 3);
		target->receive_wound("qi", damage,me);
	  message_combatd(msg, me, target);
	  target->set_temp("block_msg/all",1);
	} else {
		msg += "����$p������$P����ͼ������æ�㿪�ˡ�\n" NOR;
	message_combatd(msg, me, target);
	}
//	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		ʹ�Է�ʧȥ�Ӿ�ֱ���´ε�¼

	����Ҫ��
		��������150��
		���Ƹ�150��
		����600
HELP
	);
	return 1;
}

