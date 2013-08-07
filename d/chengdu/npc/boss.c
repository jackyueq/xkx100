// Room: /d/chengdu/npc/boss.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ϰ���", ({ "lao ban", "lao", "ban" }));
	set("nickname", "Ц����");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "Ů��");
	set("age", 36);
	set("long","���������Ц�ݣ�������ͷȴ���ѵúܡ�\n��Ϊ��ݵ��ϰ�������һ��û�¸ɵ����ļһ����һ���͵úܡ�\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		FOOD_DIR"peanut",
		FOOD_DIR"tofu",
		__DIR__"obj/longhucui",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
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
		say("�ϰ���Ц���е�˵������λ" + RANK_D->query_respect(ob) + "����������ȱ��Ȳ衣\n");
		break;
	case 1 :
		say("�ϰ���˵����Ӵ����λ" + RANK_D->query_respect(ob) + "�����˰��������и�ը�õ����㻨�����ۡ�\n");
		break;
	}
}

