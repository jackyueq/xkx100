// Room: /d/chengdu/npc/huoji.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���", ({ "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "���������м�������������ͦ�ڿ�ġ�\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		JEWELRY_DIR"necklace",
		JEWELRY_DIR"goldring",
	}));

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

