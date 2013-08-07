// Room: /d/chengdu/npc/oldwomen.c �ϴ���
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ϴ���", ({ "Old women", "old", "women" }) );
	set("gender", "Ů��" );
	set("age", 62);
	set("long",
		"���ǲ˳��ϰ壬������������Ŵ����������档\n");
	set("combat_exp", 120);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϴ���");
	set("vendor_goods", ({
		__DIR__"obj/qingcai",
		__DIR__"obj/dabaicai",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

