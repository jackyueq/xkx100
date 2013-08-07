// bidu.c
// Last Modified by Winder on Oct. 20 2000
#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3, con4, con5, con6;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/bidu") &&
  !me->query("can_perform/xiantian-qigong/bidu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	con1 = me->query_condition("snake_poison");
	con2 = me->query_condition("scorpion_poison");
	con3 = me->query_condition("xx_poison");
//	con4 = me->query_condition("ss_poison");
	con5 = me->query_condition("zhua_poison");
	con6 = me->query_condition("ice_poison");

	if(con1< 1 && con2< 1 && con3< 1 &&con4 < 1 && con5< 1 && con6< 1)
		return notify_fail("�������˹��ƶ�����������û���Ƴ�ʲô����\n");
	if( me->is_fighting() )
		return notify_fail("ս�����˹��ƶ���������������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 80)
		return notify_fail("�������������Ϊ��������\n");

	message("vision", 
	HIY+me->name()+"��ϥ���£������������˹��ƶ���ֻ��һ��"HIW"����"HIY"������ס"+me->name()+"����Ŀ��\n���ã�һ��"HIM"��Ѫ"HIY"��"+me->name()+"������Сָ�⻺������������\n" NOR,
		environment(me));

	me->add("neili", -300);
	me->add("qi", 10 + (int)me->query_skill("force")/5 );
	if(me->query("qi") > me->query("eff_qi"))
		me->set("qi", me->query("eff_qi"));
	me->start_busy(4);
	if (con1) me->clear_condition("snake_poison");
	if (con2) me->clear_condition("scorpion_poison");
	if (con3) me->clear_condition("xx_poison");
//	con4 = me->query_condition("ss_poison");
	if (con5) me->clear_condition("zhua_poison");
	if (con6) me->clear_condition("ice_poison");
	return 1;
}
int help(object me)
{
	write(WHT"\n��������֮�ƶ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˹��Ƴ����ڶ��أ������ж���Ч��
		�߶���Ы�Ӷ��������ƶ�����Ѫ��ץ

	����Ҫ��
		��������80��
		����500
HELP
	);
	return 1;
}

