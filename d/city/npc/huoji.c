// huoji. ҩ�̻��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����ƽ��ҽ������������æ�ġ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/medicine/nostrum/jinchuang",
		"/clone/medicine/nostrum/yangjing",
		"/clone/medicine/nostrum/dongshang",
		"/clone/medicine/nostrum/fashao",
		"/clone/medicine/nostrum/ganmao",
		"/clone/medicine/nostrum/shanghan",
		"/clone/medicine/nostrum/xiaoshu",
		"/clone/medicine/nostrum/zhike",
		"/clone/medicine/nostrum/zhujingchan",
		"/clone/medicine/nostrum/dust",
		"/clone/medicine/vegetable/xionghuang",
		"/clone/misc/yaojiu",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
