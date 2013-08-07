// cainong.c 
inherit NPC;
inherit F_DEALER;

void  create()
{
	set_name("��ũ", ({ "cai nong" }));
	set("gender", "����");
	set("age", 25);
	set("long", "һλ�����ڵ����²�ũ��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/bcseed",
		__DIR__"obj/qcseed",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
