// mapo.c
// Last Modifyed by Winder on Dec. 24 2001

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "chen mapo", "chen" }));
	set("title", "���Ŷ�����ʼ��");
	set("nickname",HIW "������ʩ" NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "Ů��");
	set("age", 25);
	set("long",
		"�����ſ��ǳɶ��ǳ����������Ȼ�����ʮ����Ȼ�����̴档\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
		"���Ŷ���" : "�������ǳɶ����ز������ݵú�Ŷ��\n",
	]));
	set("vendor_goods", ({
		__DIR__"obj/doufu",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("������Ц�����˵������λ" + RANK_D->query_respect(ob) +
			"���������\n");
		break;
	case 1 :
		say("������˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
			"�����˰�����������Ŷ���Ӳ�ǰ��ݵúܣ�\n");
		break;
	}
}


