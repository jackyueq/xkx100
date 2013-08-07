// Room: /d/jueqinggu/npc/gongsunlve.c
// Last Modified by winder on Feb. 17 2001

inherit NPC;

void create()
{
	set_name("��������", ({ "gongsun lve", "gongsun", "lve" }));
	set("long",
		"��üĿ���ţ������峺����ɫ���ﷺ�죬��Ǳ�����СС���롣����ȥ����һ������֮����\n");
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "friendly");
	set("shen", 3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 1000);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 80);
	set("combat_exp", 300000);

	set_skill("force", 100);
	set_skill("xuantian-wuji", 100);
	set_skill("dodge", 100);
	set_skill("kunlun-shenfa", 104);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi-jian", 100);
	set_skill("throwing", 100);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("sword", "liangyi-jian");
	set("inquiry", ([
		"���鵤": "��ҩ����ֻ�������ˣ������Ҹ����ղصĺ����ܡ�",
		"�黨": "��Щ��������ģ��������ж��ġ�",
	]) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

 
