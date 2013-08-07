// dianzhu.c 
#include <ansi.h>;
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({"dian zhu", "zhu"}));
	set("age", 52);
	set("gender", "����");
	set("per", 20);
	set("attitude", "friendly");

	set("combat_exp", 400);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);

	set("vendor_goods", ({
		__DIR__"obj/tangsancai",
		"/d/xingxiu/obj/fire",
	}));
	set("chat_chance", 20);
	set("chat_msg", ({
		"�����������������ô�����ս�ң������Ѿ������ϵ��ˣ���......\n",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",  2);
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
