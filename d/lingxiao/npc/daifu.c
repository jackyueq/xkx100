// Npc: /d/lingxiao/npc/daifu.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�����", ({ "dai daifu", "dai" }));
	set("str", 60);
	set("gender", "����");
	set("age", 18);
	set("long", "���������ǵ���ҽ,�ڳ��о�������,����𾴡�\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		NOSTRUM_DIR+"jinchuang",
		NOSTRUM_DIR+"yangjing",
		NOSTRUM_DIR+"zhujingchan",
		NOSTRUM_DIR+"hedinghong",
		NOSTRUM_DIR+"bicanfeng",
		NOSTRUM_DIR+"kongquedan",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

