// zhangqinlin.c ������ 
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "zhangqinlin", "zhang", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "�������ⲻ��ã�����������ҲûʲôЦ�ݡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "����");
	set("vendor_goods", ({
		__DIR__"obj/zongzi",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		if ( (myfam = ob->query("family")) &&
			myfam["family_name"] == "ؤ��" &&
			ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\nֻ�����ִ��һ���������Ҫ���Ľ�����ʲô�����ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/chengdu/xiaojie1");
	message("vision", "ֻ����ƹ����һ����" + ob->query("name") + "���˴����ӵ���һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
