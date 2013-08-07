// tiandi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/tiandi") &&
  !me->query("can_perform/linji-zhuang/tiandi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if (me->query_temp("ljtiandi"))
		return notify_fail("���Ѿ��������ׯ�ˣ�\n");

	if (me->query("gender") != "Ů��" || me->query("sex/number"))
		return notify_fail("�㲻�Ǵ�Ů����֮�壬���������ׯ��\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷������ׯ��\n");

	if( (int)me->query("neili") < 100)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 30)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIM "$N���������������ׯ���������������ϣ������ؽ�����������������....
���˲��ã�$N������������Ө����ɫ����������������͸���ഺ����Ϣ��\n" NOR,
	me );
	me->add("neili", -100);
	me->add("jing", -20);
	me->add("eff_jing", -10);
	me->set_temp("ljtiandi", 1);
	me->add_temp("apply/personality", (int)skill/20);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/20:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/personality",-count);
	me->delete_temp("ljtiandi");
	tell_object(me, 
HIB "��Ȼ������ͷ�е�һ��ʧ�䣬ԭ��������ׯ�չ��ˣ����ʱ
���к�����ȥ֮̾��\n" NOR );
}

int help(object me)
{
	write(WHT"\n�ټ�ʮ��ׯ֮���ׯ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʱ�����ò

	����Ҫ��
		�ټ�ʮ��ׯ30��
		����100
		��Ů����֮��
HELP
	);
	return 1;
}

