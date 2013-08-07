// guimei.c ������
// Last Modified by winder on Oct. 28 2000

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	string msg;
	int skill = me->query_skill("kuihua-xinfa",1); 

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/guimei") &&
  !me->query("can_perform/kuihua-xinfa/guimei") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( me->query_temp("bixie/guimei"))
		return notify_fail("���Ѿ������ù������˰ɣ�\n");

//	if( !target || !target->is_character() || !me->is_fighting(target) )
//		return notify_fail("��һ����������ȥ��ʲô��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if((int)me->query_skill("kuihua-xinfa", 1) < 100)
			return notify_fail(HIY "��Ŀ����ķ���Ϊ������\n" NOR);
		if((int)me->query_skill("bixie-jian", 1) < 120)
			return notify_fail(HIY "��ı�а��������������\n" NOR);
	}
	if((int)me->query("neili") < 200)
		return notify_fail(HIY "�������������㡣\n" NOR);

	msg = HIC"����$N������������ȣ�Ʈ����ȥ��ֱ�����̡�������磬ȴ�����������Ϣ��\n"NOR;
	message_combatd(msg, me);
	me->add("neili", -200);
	me->set_temp("bixie/guimei", 1);
	me->add_temp("apply/dexerity", (int)skill/30);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/30:),skill/4);
	return 1;
}

void remove_effect(object me, int count)
{
//	me->delete_temp("apply/dexerity");
  me->add_temp("apply/dexerity",-count);
	me->delete_temp("bixie/guimei");
	tell_object(me,HIY"�����һ���������µ����Ĺ������չ��ˣ�\n" NOR);
}

int help(object me)
{
	write(WHT"\n�����ķ�֮��������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʱ�����

	����Ҫ��
		�����ķ�100��
		��а����120��
		����200
HELP
	);
	return 1;
}

