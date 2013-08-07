// Room: /d/jueqinggu/npc/puren.c
// Last Modified by winder on Feb. 17 2001

inherit NPC;

void create()
{
	set_name("����", ({ "pu ren", "pu", "ren" }));
	set("long",
		"����ȵ����ˣ�����һ�������\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "friendly");
	set("shen", -1000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 300);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 10);
	set("combat_exp", 50000);

	set_skill("force", 30);
	set_skill("xuantian-wuji", 30);
	set_skill("dodge", 30);
	set_skill("kunlun-shenfa", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_skill("liangyi-jian", 30);
	set_skill("throwing", 30);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("sword", "liangyi-jian");
 
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

 
