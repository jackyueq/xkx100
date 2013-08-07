// reserve.c ��󡹦������ת
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill;
	string msg;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/reserve") &&
  !me->query("can_perform/hamagong/reserve") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

        if ( me->query("family/master_id") != "ouyang feng" )
		return notify_fail("��Ŀǰ��û�����������С���߻���ħ��\n");
		
	if( (int)me->query_skill("hamagong", 1) < 160 )
		return notify_fail("��ĸ�󡹦������죬���ᾭ����ת��\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("hmg_dzjm") ) 
		return notify_fail("���Ѿ���ת�����ˡ�\n");

	skill = me->query_skill("hamagong",1);
	msg = HIB "$N����˫�ֳŵص��������˾�������ʱ��Ϣ������������������\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", -skill/6);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("hmg_dzjm", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/2 :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("hmg_dzjm");
	tell_object(me, HIY "��˫��һ�ţ�һԾ���𣬽������ջص��\n"NOR);
}
int help(object me)
{
	write(WHT"\n��󡹦֮������ת��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ת��������ܵ�Ѩ

	����Ҫ��
		��󡹦160��
		����200
HELP
	);
	return 1;
}


