// wolf.c
// Date: Sep. 5 2000

inherit NPC;

void create()
{
	set_name("ĸ��", ({ "mu lang", "wolf", "lang" }) );
	set("race", "����");
	set("age", 5);
	set("gender", "����");
	set("long", "һֻĸ�ǣ������ŵĴ�����¶�ż��������\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("combat_exp", 20000);
	set_temp("apply/attack", 2000);
	set_temp("apply/defense", 3000);
	set_temp("apply/armor", 800);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"ĸ��������β�ͣ�ͻȻ̧ͷ�����㷢��һ�������ĳ�����\n",
		"ĸ�����������ĵ��۹���������飬Ѫ��޿�������Ź����ӡ�\n",
	}) );
}

