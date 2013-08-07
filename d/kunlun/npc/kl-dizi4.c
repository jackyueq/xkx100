// kunlun-dizi1.c (kunlun)

inherit NPC;

void create()
{
	set_name("�����ɵ���", ({ "dizi"}));
	set("long",
		"��������������Բ���ƺ�����һ���书��\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 30000);
	set("score", 4000);

	set_skill("force", 40);
	set_skill("xuantian-wuji", 40);
	set_skill("dodge", 50);
	set_skill("taxue-wuhen", 50);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("strike", 40);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");

	create_family("������", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao4")->wear();
}


