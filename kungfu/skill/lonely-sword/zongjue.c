// zongjue.c ���ܾ�ʽ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost, exp, myint;
	int skill_basic;
	mapping my_fam = me->query("family");

	skill = me->query_skill("lonely-sword",1);
	skill_basic = me->query_skill("sword",1);
	jing_cost = (int)me->query("int") - 45;

	if(!my_fam || my_fam["master_id"] != "feng qingyang")
		return notify_fail("�㲻�Ƿ�����մ����ӣ�����ʹ���ܾ�ʽ��\n");
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/zongjue") &&
  !me->query("can_perform/lonely-sword/zongjue") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�");
   	if(environment(me)->is_chat_room()) return notify_fail("���ﲻ׼�򶷡�\n");
	if( me->is_fighting() )
		return notify_fail("���ܾ�ʽ��������ս����������\n");
	myint = me->query("int");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("�������ȥ��һ�ѽ���\n");

	if( !skill || (skill < 20))
		return notify_fail("��Ķ��¾Ž��ȼ�����, ���������ܾ�ʽ��\n");
	if( me->query("neili") < 50 )
		return notify_fail("�������������û�������������ܾ�ʽ����\n");
	if( me->query("jing") < -jing_cost )
		return notify_fail("������̫���ˣ��޷����о��������ܾ�ʽ��\n");

	exp= (int)me->query("combat_exp");
	if( skill*skill*skill/10>exp )
		return notify_fail("���ʵս���鲻�����޷���ᡸ�ܾ�ʽ����\n");

	msg= HIG"$Nʹ�����¾Ž�֮���ܾ�ʽ����������"+weapon->name()+HIG"���������̡�\n"NOR;
	message_combatd(msg, me);
	me->add("neili", -50);
	me->add("jing", jing_cost);
	if ( skill < 60) me->improve_skill("lonely-sword",10,skill_basic > skill? 0: 1);
	else if (skill < 90)
		me->improve_skill("lonely-sword",10+random(myint-9),skill_basic > skill? 0: 1);
	else if (skill < 140)
		me->improve_skill("lonely-sword",10+random(myint*2-9),skill_basic > skill? 0: 1);
	else if (skill < 200)
		me->improve_skill("lonely-sword",10+random(myint*4-9),skill_basic > skill? 0: 1);
	else me->improve_skill("lonely-sword",10+random(myint*8-9),skill_basic > skill? 0: 1);

	msg = MAG"$P�ġ����¾Ž��������ˣ�\n"NOR;
	me->start_busy(random(2));
	message_combatd(msg, me);
	return 1;
}
int help(object me)
{
	write(WHT"\n���¾Ž�֮�ܾ�ʽ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʾ�ܾ�����߶��¾Ž�����Ϊ

	����Ҫ��
		��Ϊ������մ�����
		���¾Ž�20��
		����50
HELP
	);
	return 1;
}

