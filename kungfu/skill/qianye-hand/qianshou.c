// qianshou ǧ������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "��ǧ��������"
void back(object target, int skill);
int perform(object me, object target)
{
	string msg;
	int skill;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("ʹ�á�ǧ��������ʱ˫�ֱ�����ţ�\n");

	fskill = "zhanzhuang-gong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( target->query_temp("qianshou"))
		return notify_fail("�Է������ˡ�ǧ����������\n");

	if( (int)me->query_dex() < 27 )
		return notify_fail("���������ǿ������ʹ�á�ǧ����������\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("����������̫��������ʹ�á�ǧ����������\n");

	skill = (int)me->query_skill(bskill, 1)/10;

	msg = HIY"$N"HIY"˫�ֺ�ʮ��������Ȼ����һ�֣�˫�ƶ�ʱ�������Ʈ�ݣ��鶯�쳣����ʱ�����������Ӱ��\n" NOR;
	msg += HIR "$n"HIY"ֻ�������ܶ���$N����Ӱ�����ɵû���������\n" NOR;
	message_combatd(msg, me, target);

	target->add_temp("apply/attack", -skill);
	target->add_temp("apply/dodge", -skill);
	target->add_temp("apply/parry", -skill); 
	target->set_temp("qianshou",1);   
	me->add("neili", -500);
	target->start_call_out( (: call_other, __FILE__, "back", target, skill :),skill/10);

	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

void back(object target, int skill)
{
	target->add_temp("apply/attack", skill);
	target->add_temp("apply/dodge", skill);
	target->add_temp("apply/parry", skill);
	target->delete_temp("qianshou");
	tell_object(target, HIB"�㽥����Ӧ�����ֱ仯��״̬�ָֻ��糣��\n"NOR);
}

int help(object me)
{
	write(HIC"\nǧҶ������֮ǧ��������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		ʹ���ֵĹ������ͷ�������һ��ʱ�����½���
		��ʮ������������

	����Ҫ��
		վ׮��100��
		����ǧҶ��100
		������27
		����1000
HELP
	);
	return 1;
}

