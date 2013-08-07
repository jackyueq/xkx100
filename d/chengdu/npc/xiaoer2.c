// Room: /d/chengdu/npc/xiaoer2.c �Ƶ�С��
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		FOOD_DIR"jitui",
		LIQUID_DIR"jiudai",
		FOOD_DIR"baozi",
		__DIR__"obj/langjiu",
		__DIR__"obj/feipian",
		__DIR__"obj/wuliangye",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{	
	object ob = this_player();
	mapping myfam; 

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

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob) + "����ӭ�������Ӿ�¥��\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob) + "����������\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/chengdu/chunxilu1");
	message("vision","ֻ����ƹ����һ����" +  ob->query("name") + "���˴����Ӿ�¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
