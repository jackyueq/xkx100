// youming.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	object obj;
	int skill;
	
	seteuid(getuid());
	skill = (int)me->query_skill("linji-zhuang",1);
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/youming") &&
  !me->query("can_perform/linji-zhuang/youming") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if (!wizardp(me))
	{
	if (me->query("gender") != "Ů��")
		return notify_fail("�㲻�Ǵ���֮�壬��������ڤׯ��\n");

	if (me->query("sex/number") )
		return notify_fail("�㲻�Ǵ�Ů֮����������ڤׯ��\n");

	if( me->is_busy() )
		return notify_fail("������̫�ۣ�\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷�����ڤׯ��\n");

	if( !me->query("dietime"))
		return notify_fail("��δ����ڤ���������˴�ׯ��\n");

	if( me->query("dietime") < time() - 300)
		return notify_fail("���뿪��ڤ�Ѿã�������ڤ������\n");

	if( (int)me->query("neili") < 1000)
		return notify_fail("�������������\n");

	if( me->query("jing") < 100 || me->query("qi") < 200)
		return notify_fail("��ľ���������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 180)
		return notify_fail("����ټ�ׯ���𲻹���\n");
	}
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIG"$N������������"HIB"��ڤׯ"HIG"��˫�Ʊ�������"MAG"����"HIG"�������н���͸��������\n��֮�佻�㼤��������"HIY"����֮��"HIG"������"MAG"����"HIG"������Ͷ���"HIW"�׹�"HIG"���ֻ���\n��"HIR"ҫĿ"HIG"����������һ�����ı��죬$N��˫���͵غ�����һ��$N����\n���ƣ��ǻ���һ����Ө��͸��"HIW"���衣\n" NOR, me );
	message_vision("\n$N����һ�����ڵ��ϣ�ʵ��̫���ˣ�����������\n",me);
	me->add("neili", -1000);
	me->receive_wound("jing", 100);
	me->receive_wound("qi", 100);
	obj = new("/clone/medicine/nostrum/guiyuandan");
	obj->set("owner",me);
	obj->move(me);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
	write(WHT"\n�ټ�ʮ��ׯ֮��ڤׯ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���ƹ�Ԫ��

	����Ҫ��
		�ټ�ʮ��ׯ180��
		����1000
		����100
		��Ѫ200
		��Ů����֮��
HELP
	);
	return 1;
}

