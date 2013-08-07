// chaboshi.c �販ʿ

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�販ʿ", ({ "cha boshi", "boshi", "cha" }));
	set("title", "�������");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 25);
	set("combat_exp", 800);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
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
	if (!ob || environment(ob) != environment()) return;
	say("�販ʿЦ���е�˵������λ" + RANK_D->query_respect(ob) + "����������ȱ��Ȳ裬�մ�ɽ�����µ�Ȫˮ��ġ�\n");
}
