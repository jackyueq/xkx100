// shiye.c ֪��ʦү

inherit NPC;

string ask_me();

void create()
{
	set_name("���ı�", ({ "he wenbao", "he" }));
	set("title", "֪��ʦү");
	set("gender", "����");
	set("age", 47);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen_type", 0);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
