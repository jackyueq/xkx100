// alabo.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("����������", ({ "alabo shangren", "shangren", "trader" }));
	set("gender", "����");
	set("age", 35);
	set("long","һ�����������ˡ�ͷ�ϰ���һ��׽�\n");
	set("attitude", "friendly");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 40);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"���������˶��㼷��һ���۾���\n",
		"���������˶���˵�����������빱���º�Ĭ�����ذ�������û������\n",
		(: random_move :)
	}) );
	carry_object("/clone/weapon/blade/wandao")->wield();
	carry_object("/clone/cloth/changpao")->wear();
	add_money("silver", 20);
}


