// Room: /d/kunlun/npc/puren.c
// Last Modified by winder on Nov. 14 2000

inherit NPC;

void create()
{
	set_name("����", ({"pu ren", "pu"}) );
	set("gender", "����" );
	set("age", 50);
	set("long",
	"���Ǹ���ʵ�ͽ��������ˣ���Ȼ�·��ϴ��˺ܶಹ����ȴ��ʮ�ֵ����ࡣ\n"
	"��Ϊ���ڴ��ڳ�����۾�����Ѭ����һ���졣\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 24);

	set("max_qi", 650);
	set("max_jing", 400);
	set("neili", 150);
	set("max_neili", 150);

       	set("combat_exp", 1000+random(800));
	set("score", 1000);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 25+random(20));
	set_skill("parry", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 4);
//	create_family("������", 24, "����");
	setup();
	carry_object("/d/kunlun/obj/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say("����Ц������˵������λ" + RANK_D->query_respect(ob)
		+ "����������" + "����͸����ϲ衣\n");
}

void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;

	if( !objectp(room = environment()) ) return;

	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
		obn = new("/d/kunlun/obj/dawancha");
		obn->move(room);
		message_vision("���˰�����������������ϵĴ���赹����\n",
			who);
	} else
	{
		who->add_temp("tea_cup", -1);
		obn = new("/d/kunlun/obj/xiangcha");
		obn->move(room);
		message_vision("�����ó�������С��������˱���裬�������ϣ�\n",
			who);
	}

	obn = new("/d/kunlun/obj/rice");
	obn->move(room);
	message_vision("����ʢ��һ������õĴ��׷����������ϡ�\n", who);

	return;
}
