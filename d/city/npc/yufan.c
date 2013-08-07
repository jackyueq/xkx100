// yufan.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����Ȼ" , ({ "leng yuran", "leng" }) );
	set("rank_info/zhiye","����ϰ�");
	set("gender", "����" );
	set("age",45);
	set("combat_exp", 1500000);
	set_skill("unarmed",30);
	set_skill("dodge",30);
	set("attitude", "friendly");
	set("vendor_goods", ({
		JEWELRY_DIR+"yujie",
		JEWELRY_DIR+"yudai",
		JEWELRY_DIR+"yufa",
		JEWELRY_DIR+"yushou",
		JEWELRY_DIR+"yuruyi",
		JEWELRY_DIR+"yubei",
		JEWELRY_DIR+"yuzhan",
	}) );
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (environment(ob)==environment())
	message_vision("����ϰ��$PЦ����ӭ������㿴����\n",ob);
	return;
}
