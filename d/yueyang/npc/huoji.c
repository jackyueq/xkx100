// huoji. ҩ�̻��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����һ����̫��ʵ�Ļ�ơ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/medicine/nostrum/jinchuang",
		"/clone/medicine/nostrum/yangjing",
		"/clone/medicine/nostrum/dust",
		"/clone/medicine/vegetable/xionghuang",
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
