// flowerg.c

inherit NPC;
inherit F_DEALER;

int ask_for_h();

int heye = 1;

void create()
{
	set_name("��������", ({ "flower girl","girl"}) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long", "һ����ò������С���\n");
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/baihe",
		__DIR__"obj/huaban"
	}));
	set("inquiry", ([
		"��Ҷ"	: (: ask_for_h :),
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int ask_for_h()
{
	object me = this_player(), ob;
	
	if ( heye == 0 || random(me->query("kar")) < 10 ) 
		return 0;
	else {
		message_vision("�������￴��$N�ԳԵ�Ц��������\n", me );
		command("say �Һͽ�������ˣʱժ�ĺ�Ҷ��ҲҪ��" );
		message_vision("���������͸�$N��Ƭ��Ҷ��\n", me );
		ob = new( __DIR__"obj/heye" );
		ob->move( me );
		heye = 0;
	}
	return 1;	
}
