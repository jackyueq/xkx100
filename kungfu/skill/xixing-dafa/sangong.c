// sangong.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
//  if ( userp(me) && !wizardp(me) && 
//  !me->query("perform/sangong") &&
//  !me->query("can_perform/xixing-dafa/sangong") && 
//  !me->query_temp("murong/xingyi"))
//   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if( me->is_fighting() ) return notify_fail("ս����ɢ����������\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if((int)me->query_skill("xixing-dafa", 1) > 20)
		return notify_fail("�����ڲ���ɢ����\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("�����˹��أ�ֻ��һ��������������Σ�գ�\n");

	message_vision( HIY"$N��������ʼɢ����������ﳣ����䣬������ȣ�����������ȿ���ˮ��������Ϣ��ɢ֮��������Ѩ����\n" NOR, me);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"sangong",me :),5);
	return 1;
}
void sangong(object me)
{
	object ob;
	message_vision(HIG"$N��ʱ���õ���������ɢ֮�����������пգ��ƹȺ��顭��\n"NOR,me);
	me->set("max_neili", 0);
	me->set("neili", 0);
	return;
}

int help(object me)
{
	write(WHT"\n���Ǵ�֮ɢ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ϰ���Ǵ󷨱��뾭��ɢ����ɢȥȫ������

	����Ҫ��
		���Ǵ�С��10��
HELP
	);
	return 1;
}

