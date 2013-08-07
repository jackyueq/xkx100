// taiji.c ��̫���ķ���
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{
	object weapon = me->query_temp("weapon");
	string prepare;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/taiji") &&
  !me->query("can_perform/taiji-shengong/taiji") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( !objectp(weapon) &&
		me->query_skill_mapped("unarmed") == "taiji-quan" &&
		me->query_skill_mapped("parry") == "taiji-quan" &&
		me->query_skill_mapped("force") == "taiji-shengong" )
		prepare = "tjq"; // player is using tjq.
	else
		if( objectp(weapon) &&
			weapon->query("skill_type") == "sword" &&
			me->query_skill_mapped("sword") == "taiji-jian" &&
			me->query_skill_mapped("parry") == "taiji-jian" &&
			me->query_skill_mapped("force") == "taiji-shengong" )
			prepare = "tjj"; // player is using tjj. 
		else prepare = "notj";
	if( me->query_temp("taiji") )
		return notify_fail("���Ѿ���̫���ķ��ڻ����书֮�С�\n");
	if( prepare == "notj" )
		return notify_fail("�������޷���̫���ķ��ڻ����书�ڡ�\n");
	if( prepare == "tjj" && me->query_skill("taiji-jian", 1) < 300 )
		return notify_fail("����δ��ᵽ̫�����⡣\n");
	if( prepare == "tjq" && me->query_skill("taiji-quan", 1) < 300 )
		return notify_fail("����δ��ᵽ̫��ȭּ��\n");
	if( me->query_skill("taiji-shengong", 1) < 300 )
		return notify_fail("���̫����Ϊ��δ�Ƿ��켫���޷��������ķ���\n");
	if( me->query_skill("taoism", 1) < 150 )
		return notify_fail("��ĵ�ѧ��Ϊ��δ��Ȼ��ͨ���޷����̫���ķ���\n");
	if( userp(me) && me->query_int() < 50 )
		return notify_fail("�������̫�ͣ��޷���ᵽ̫���ķ���\n");
  if( me->query_temp("wudang/raozhi"))
    return notify_fail("������ʩչ����ָ�ὣ����û��̫�ྫ������̫���ķ���\n");
	if( prepare == "tjj" )
		message_combatd( "\n$N΢΢һЦ�����ӻ�����ת�����ֳֽ��������𣬽�������ǰ��\n����˫��������ԣ��籧Բ��" + weapon->name() + "δ������Ȼ�������\n", me);
	else
		message_combatd( "\n$N����վ��������˫���´����ֱ����⣬��ָ΢�棬����ֿ�ƽ�У�\n��������������������ǰ����۰뻷��������Գ����ƣ����Ʒ��������ơ�\n", me);

  if (userp(me))
	me->receive_damage("jing", 500, "����͸֧��������");
	me->add_temp("taiji", (int)me->query_skill("taiji-shengong", 1)/2);

	call_out("checking", 1, me, prepare);

	return 1;
}

void checking(object me, string prepare)
{
	object weapon = me->query_temp("weapon");
	string tjjzhao, tjqzhao1, tjqzhao2, tjqzhao3;

	tjjzhao = SKILL_D("taiji-jian")->query_skill_name(random(140));
	tjqzhao1 = SKILL_D("taiji-quan")->query_skill_name(random(150));
	tjqzhao2 = SKILL_D("taiji-quan")->query_skill_name(random(150));
	tjqzhao3 = SKILL_D("taiji-quan")->query_skill_name(random(150));

	if( me->query_temp("taiji") < 1 )
	{
		remove_effect(me);
		tell_object(me, "\n������������ϣ����������ڵ�����Ϲ�Ԫ��\n");
		return;
	}
	else if( !living(me) || me->is_ghost() )
	{
		remove_effect(me);
		return;
	}
	else if( prepare == "tjq" && objectp(weapon) )
	{
		remove_effect(me);
		return;
	}
	else if( prepare == "tjj" && (!objectp(weapon) ||
		weapon->query("skill_type") != "sword") )
	{
		if( me->query_temp("taiji_fight") )
			message_combatd(CYN"\n$N�����޽��������ʧ��\n"NOR, me);
		remove_effect(me);
		return;
	}
	else if( me->query_skill_mapped("force") != "taiji-shengong")
	{
		remove_effect(me);
		tell_object(me, HIR"\n������ؿ�һ�󷳶�ԭ�������ڹ���̫���ķ����棡\n" NOR);
		me->receive_damage("qi", 1000, "�ڹ��߻���ħ����");
		return;
	}
	else if( !me->is_busy() )
	{
		if( me->query_temp("taiji_fight") && !me->is_fighting() )
		{
			remove_effect(me);
			if( prepare == "tjj" )
				message_combatd("\n$Nʹ��" + tjjzhao + "��˫��ͬʱ��Բ�����ɵ���ʮ��ʽ���ֽ���ԭ����\n"NOR, me);
			else
				message_combatd("\n$Nʹ���ϲ�"+ tjqzhao1 + "���ϲ�" + tjqzhao2 + "��" + tjqzhao3 + "����̫���������е�վ�ڵ��ء�\n"NOR, me);
			return;
		}
		else if( prepare == "tjj" &&
			(me->query_skill_mapped("sword") != "taiji-jian" ||
			me->query_skill_mapped("parry") != "taiji-jian") )
		{
			if( me->query_temp("taiji_fight") )
				message_combatd(CYN"\n$NȦת" + weapon->name() + CYN"��ͻȻ���У�ʹ����̫�����ⲻͬ�Ľ�����\n"NOR, me);
			remove_effect(me);
			return;
		}
		else if( prepare == "tjq" &&
			(me->query_skill_prepared("unarmed") != "taiji-quan" ||
			me->query_skill_mapped("unarmed") != "taiji-quan" ||
			me->query_skill_mapped("parry") != "taiji-quan") )
		{
			if( me->query_temp("taiji_fight") )
				message_combatd(CYN"\n$N˫��һ��ͻȻʹ����̫��ȭּ�෴��������\n"NOR, me);
			remove_effect(me);
			return;
		}
	}

	if( !me->query_temp("taiji_fight") ) me->add_temp("taiji", -1);
	call_out("checking", 1, me, prepare);
} 

void remove_effect(object me)
{
	me->delete_temp("taiji");
	if( me->query_temp("taiji_fight") ) me->delete_temp("taiji_fight");
	me->start_busy(1);
}

int help(object me)
{
	write(WHT"\n̫����̫֮���ķ���"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		̫���ķ���ʹ�ã��������䵱���Ź��������

	����Ҫ��
		̫����300��
		̫��ȭ300��
		̫������300��
		��ѧ�ķ�150��
		�������Բ�����50
		����ʱ�輤��̫��ȭΪ�м������ȭ��
		�ֽ�ʱ�輤��̫������Ϊ�м����������
HELP
	);
	return 1;
}

