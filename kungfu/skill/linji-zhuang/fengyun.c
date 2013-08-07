// fengyun.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/fengyun") &&
  !me->query("can_perform/linji-zhuang/fengyun") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if (me->query_temp("ljfengyun"))
		return notify_fail("���Ѿ����˷���ׯ�ˣ�\n");

	if (me->query("gender") != "Ů��" || me->query("sex/number"))
		return notify_fail("�㲻�Ǵ�Ů����֮�壬�����˷���ׯ��\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷��˷���ׯ��\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 120)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIC "$N���������������ׯ�������������˵�����ӿȪѨ��....
��������һ��ů�������ӿ��ӿ���ϣ���ʱ�����������࣬ԾԾ���ɡ�\n" NOR, me);
	me->add("neili", -400);
	me->add("jing", -20);
	me->set_temp("ljfengyun", 1);
	me->add_temp("apply/dexerity", (int)skill/40);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/40:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/dexerity",-count);
	me->delete_temp("ljfengyun");
	tell_object(me, 
HIB"��Ȼ�����һ�����������������³�ȥ����ʱ˫�����Ǧ���
�أ�ԭ����ķ���ׯ�չ��ˣ�\n" NOR );
}

int help(object me)
{
	write(WHT"\n�ټ�ʮ��ׯ֮����ׯ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʱ�����

	����Ҫ��
		�ټ�ʮ��ׯ120��
		����400
		��Ů����֮��
HELP
	);
	return 1;
}

