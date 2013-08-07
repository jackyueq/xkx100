// tiejiang.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "tiejiang", "smith" }));
	set("shen_type", 1);
	set("gender", "����" );
	set("age", 33);
	set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/clone/weapon/gangjian",
		"/clone/weapon/gangdao",
		"/clone/weapon/tiejia",
	}));
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

