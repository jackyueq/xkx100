// shiqing.c

inherit NPC;

void create()
{
	set_name("������ʦ", ({ "shiqing chanshi", "chanshi", "shiqing" }) );
        set("title", "ʮ���·���");
	set("gender", "����");
	set("age", 20);
	set("long",
		"����һ����������ĺ��С�\n");
	set("combat_exp", 120000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);

	setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver", 10);
}
