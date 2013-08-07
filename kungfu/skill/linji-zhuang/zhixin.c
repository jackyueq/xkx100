// zhixin.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/zhixin") &&
  !me->query("can_perform/linji-zhuang/zhixin") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if (me->query_temp("ljzhixin"))
		return notify_fail("���Ѿ�����֮��ׯ�ˣ�\n");

	if (me->query("gender") != "Ů��")
		return notify_fail("�㲻�Ǵ���֮�壬������֮��ׯ��\n");

//	if (me->query("sex/number") )
//		return notify_fail("�㲻�Ǵ�Ů֮����������ڤׯ��\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷���֮��ׯ��\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 60)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIY "$N������������֮��ׯ���������������Ͽ������£��پ���̨������....
վ�������������Դ�������˲��١�\n" NOR, me );
	me->add("neili", -200);
	me->add("eff_jing", -10);
	me->add("jing", -20);
	me->add_temp("apply/intelligence", (int)skill/40);
	me->set_temp("ljzhixin", 1);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/40:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/intelligence",-count);
	me->delete_temp("ljzhixin");
	tell_object(me, 
HIB "��Ȼ��ͷ����е�һ��հף�ԭ�����֮��ׯ�չ��ˣ����ʱ
�����Լ����Ǹ���ľ�ϣ�\n" NOR );
}

int help(object me)
{
	write(WHT"\n�ټ�ʮ��ׯ֮֮��ׯ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʱ�������

	����Ҫ��
		�ټ�ʮ��ׯ60��
		����200
		��Ů����֮��
HELP
	);
	return 1;
}

