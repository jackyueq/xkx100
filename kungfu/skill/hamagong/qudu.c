// qudu.c
// Last Modified by winder on Mar. 10 2000
/* ����Ϊ����͵Ķ���
�����ɣ�bt_poison ���߶�
	cold_poison ����
	hot_poison �ȶ�
	snake_poison �߶�
�����ɣ�fushi_poison ��ʬ��
	poison_sandu ɢ������
	slumber_poison �ɺ�ҩ
	sanxiao_poison ��Ц��ңɢ
	xx_poison �����ƶ�
�嶾�̣�chanchu_poison ��ܶ�
	snake_poison �߶�
	wugong_poison ��򼶾
	wuxing_poison ���ζ�
	xiezi_poison Ы�Ӷ�
	zhizhu_poison ֩�붾
����ȣ�qinghua_poison �黨��
���̣�	ice_poison �������ƶ�
��ң�ɣ�ss_poison ������
��Ĺ�ɣ�ice_sting �������붾
�����ţ�zhua_poison ��Ѫ��ץ
ѩɽ�ɣ�dashouyin ����ӡ
��������flower_poison �ϳ�����
���ݣ�	scorpion_poison Ы�Ӷ�
������	ill_dongshan ����
	ill_fashao ����
	ill_kesou ����
	ill_shanghan �˺�
	ill_zhongshu ����
δ�ã�	bing_poison ������
	cuff_power ȭ��
	iceshock �⺮�ƶ�
	rose_poison ��õ�嶾
*/
#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/qudu") &&
  !me->query("can_perform/hamagong/qudu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( me->is_fighting() )
		return notify_fail("ս�����˹�������������\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�һ��������������Σ�գ�\n");
	if ((int)me->query_skill("xidu-poison", 1) < 50)
		return notify_fail("��ԡ����������������Ǻܾ�ͨ��\n");
	if ((int)me->query_skill("hamagong", 1) < 50)
		return notify_fail("��ĸ�󡹦��Ϊ��������\n");

	if ((int)me->query_condition("bt_poison") > 0 ||
		me->query_condition("cold_poison") > 0 ||
		me->query_condition("hot_poison") > 0 ||
		me->query_condition("snake_poison") > 0 ||
		me->query_condition("fushi_poison") > 0 ||
		me->query_condition("slumber_poison") > 0 ||
		me->query_condition("xx_poison") > 0 ||
		me->query_condition("chanchu_poison") > 0 ||
		me->query_condition("wugong_poison") > 0 ||
		me->query_condition("xiezi_poison") > 0 ||
		me->query_condition("zhizhu_poison") > 0 ||
		me->query_condition("ice_sting") > 0 ||
		me->query_condition("scorpion_poison") > 0)
	{
		write(HIG"�㵹����Ϣ��ͷ�½��ϣ���Ѫ���У��������ӽ�������֮�����˳�ȥ��\n"NOR);
		message("vision", HIW+me->name()+"���ϰ���һ�ּ������ſں���һ����\n�³�һ��"HIY"��Ӳӵ���Ѫ"HIW"��һ�ε�"BLK"��Ѫ"HIW"���˿�����������\n"NOR,environment(me));
		me->clear_condition("bt_poison");
		me->clear_condition("cold_poison");
		me->clear_condition("hot_poison");
		me->clear_condition("snake_poison");
		me->clear_condition("fushi_poison");
		me->clear_condition("slumber_poison");
		me->clear_condition("xx_poison");
		me->clear_condition("chanchu_poison");
		me->clear_condition("wugong_poison");
		me->clear_condition("xiezi_poison");
		me->clear_condition("zhizhu_poison");
		me->clear_condition("ice_sting");
		me->clear_condition("scorpion_poison");
		me->add("neili", -500);
		me->start_busy(6);
		return 1;
	}
	else
	return notify_fail("���������˿��������С��������������ؽ��˼�����\n"); 
}

int help(object me)
{
	write(WHT"\n��󡹦֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�������ڶ��أ������ж���Ч��
		���չ��߶����������ȶ����߶�����ʬ�����ɺ�ҩ��
		�����ƶ�����ܶ�����򼶾��Ы�Ӷ���֩�붾���������붾

	����Ҫ��
		��󡹦50��
		��������50��
		����500
HELP
	);
	return 1;
}

