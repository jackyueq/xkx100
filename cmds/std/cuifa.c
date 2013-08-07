// cuifa.c

inherit F_SSERVER;
#include <ansi.h>
void sanshi(object me, object target);

int main(object me, string arg)
{
	object target;
	if( me->is_fighting() ) return notify_fail("ս���д߷���������\n");
	if(me->query("family/master_id") != "ren woxing")
		return notify_fail("�㲻���ν����ĵ��ӣ��޷��߷���ҩ��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if((int)me->query_skill("xixing-dafa", 1) < 100)
		return notify_fail("������Ǵ���Ϊ��������\n");
	if((int)me->query_skill("kuihua-xinfa", 1) < 100)
		return notify_fail("��Ŀ����ķ���Ϊ̫�͡�\n");
	if((int)me->query("qi") < 300) 
		return notify_fail("�����������\n");
	if((int)me->query("neili") < 400) 
		return notify_fail("�������������\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("�����˹��أ�ֻ��һ��������������Σ�գ�\n");
	if ( !arg ) return notify_fail("��Ҫ�߷�˭���ϵĵ�ҩ��\n");
	if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ�߷����˾�������ߣ����±�����\n");
	target = find_player(arg);
	if (!target) target = find_living(arg);
	if (!target || !me->visible(target)) return notify_fail("��Ҫ�߷���������û�ڰɣ�\n");

	write( HIW "����ϥ��������ʼ�߷���ʬ���񵤡�\n" NOR);
	message("vision", HIW + me->name() + "�������Ǵ󷨣���ϥ���£���ʼ�߷���ʬ���񵤡�\n" NOR, environment(me), me);
	me->add("neili", -300);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"sanshi",me,target :),5);
	return 1;
}
void sanshi(object me, object target)
{
	message_vision("$N��ϥ���������ﲻ֪����߶��ʲô��\n",me);
	if (!target->query("sanshi") )
	{
		tell_object(me, "���Ȼ���ò���ͷ��"+target->query("name")+"����û�б���ʬ�棡\n");
		return;
	}
	if (target->query("sanshi") != me->query("id"))
	{
		tell_object(me, "���Ȼ���ò���ͷ��"+target->query("name")+"�����ֵĲ������ʬ�棡\n");
		return;
	}
	tell_object(target, "���Ȼ����ͷ��֪ʲôԭ����������������ʹ�����֡���Ȼ������ʬ�淢����ֻ����ͷ��һ�䣬��ʲôҲ��֪���ˣ�\n");
//	target->die();
	target->delete("sanshi");
	target->receive_wound("qi", 10000,"��ʬ����ͻ�����������ǿ�ϧ��");
	target->receive_damage("qi", 10000,"��ʬ����ͻ�����������ǿ�ϧ��");
	target->receive_wound("jing", 10000,"��ʬ����ͻ�����������ǿ�ϧ��");
	target->receive_damage("jing", 10000,"��ʬ����ͻ�����������ǿ�ϧ��");
//message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+target->query("name")+"��ʬ����ͻ�����������ǿ�ϧ��\n"NOR, users());
	return;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : cuifa <����>
 
    ���ָ������߷�һ���������ϵ���ʬ���񵤡���Ȼ��ֻ�г���
�����ʬ���񵤵��˲Żᱻ��߷���

HELP
	);
	return 1;
}
 
