// aman.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "a man", "man"}));
	set("gender", "Ů��");
	set("age", 18);
	set("long", 
"һ�������Ĺ����˹�����յ����¡�\n");
	set("combat_exp", 2000);
	set("shen_type", 1);

	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

