// wolf.c
// Last Modified by Winder on May. 15 2001
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "wolf", "yelang", "lang" }) );
	set("race", "����");
	set("age", 5);
	set("long", "һֻ���е�Ұ�ǣ������ŵĴ�����¶�ż��������\n");
//	set("attitude", "aggressive");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 20000);
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 90);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 20);
	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"Ұ��������β�ͣ�ͻȻ̧ͷ�����㷢��һ�������ĳ�����\n",
		"Ұ�����������ĵ��۹���������飬Ѫ��޿�������Ź����ӡ�\n",
	}) );
}

