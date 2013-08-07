// runyu.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>;
int do_send(string arg);
void create()
{
	set_name( WHT"����"NOR , ({ "run yu", "yu" }) );
	set("title", MAG"��������"NOR );
	set("gender", "Ů��" );
	set("age",16);
	set("per",23);
	set("combat_exp", 1500);
	set("attitude", "friendly");

	set("vendor_goods", ({
		__DIR__"obj/red_rose",
		__DIR__"obj/yellow_rose",
		__DIR__"obj/yujinxiang",
		__DIR__"obj/kangnaixin",
		"/d/luoyang/npc/obj/chahua",
		"/d/luoyang/npc/obj/lanhua",
		"/d/luoyang/npc/obj/mudan",
		"/d/luoyang/npc/obj/chahua",
		"/d/luoyang/npc/obj/chahua",
	}));

	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
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
	if( !ob || environment(ob) != environment( this_object() ) )
	return;

	if ( ob->query("gender") == "Ů��" )
	{
		if ( ob->query("age") < 30 )
		{
			message_vision("���������$P����һЦ�����ﲻ�����������\n",ob);
			return;
		}
	}
	else
	{
		if ( ob->query("couple" ) )
		{
			message_vision("�����������$PЦ�ţ���������������������\n",ob);
			return;
		}
		else
		{
			message_vision("�����������$PЦ�ţ�����������������õ����\n",ob);
			return;
		}
	}
	return;
}

