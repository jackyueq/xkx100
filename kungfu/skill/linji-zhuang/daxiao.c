// daxiao.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/daxiao") &&
  !me->query("can_perform/linji-zhuang/daxiao") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if (me->query_condition("linji_daxiao") || me->query("linji/jing")>0)
		return notify_fail("���Ѿ����˴�Сׯ�ˣ�\n");

	if (me->query("gender") != "Ů��" || me->query("sex/number") )
		return notify_fail("�㲻�Ǵ�Ů����֮�壬�����˴�Сׯ��\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷��˴�Сׯ��\n");

	if( (int)me->query("neili") < 500)
		return notify_fail("�������������\n");

	if( (int)me->query("jing") < skill + 100)
		return notify_fail("��ľ������˴�Сׯ��\n");

	if( (int)me->query_skill("linji-zhuang",1) < 150)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "���Ѿ����˹��أ��޷��˹���\n");

	if( (int)me->query("qi") < skill ||
		(int)me->query("max_qi") < skill ||
		(int)me->query("eff_qi") < skill)
		return notify_fail("�������״�����ڲ�������ת�˹�����\n");

	message_vision("$N�������������Сׯ���������ɣ�����ֱ͸���ء�������ɫһ���"HIR"��"NOR"��һ\n���"HIC"��"NOR"��һ���ֱ��"HIY"��"NOR"ɫ��������ڻظ�ԭ������ɫ��\n"NOR,me);
	me->apply_condition("linji_daxiao", (int)skill/20);
	me->add("neili",  -500);
	me->add("max_jing", 0 - skill);
	me->add("eff_jing", 0 - skill);
	me->add("jing", 0 - skill);
	me->add("max_qi", 2 * skill);
	me->add("eff_qi", 2 * skill);
	me->add("qi", 2 * skill);
	me->set("linji/jing", skill);
	me->save();
	return 1;
}

int help(object me)
{
	write(WHT"\n�ټ�ʮ��ׯ֮��Сׯ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��������

	����Ҫ��
		�ټ�ʮ��ׯ150��
		����500
		��Ů����֮��
HELP
	);
	return 1;
}

