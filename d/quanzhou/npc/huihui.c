// huihui.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("�ػ�", ({ "hui hui", "huihui", "hui" }));
	set("gender", "����");
	set("age", 25);
	set("long","һ���ϻػأ������ڵ���������Ĥ�ݡ�\n");
	set("attitude", "friendly");
	set("combat_exp", 1000);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/clone/cloth/changpao")->wear();
	add_money("silver", 5);
}


