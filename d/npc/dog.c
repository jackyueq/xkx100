//dog.c

#include <ansi.h>
#include <command.h>

inherit NPC;

void create()
{
	set_name("С��", ({ "dog" }) );
	set("title", "������С����");
	set("race", "����");
	set("gender", "����" );
	set("age", 10);
	set("str", 22);
	set("int", 30);
	set("dex", 30);
	set("con", 30);

	set("long", "�㿴�������������׵�С����\n");
	set("combat_exp", 2000000);
	set("attitude", "friendly");

	set("max_qi", 10000);
	set("max_jing", 10000);
	set("inquiry", ([
		"����" : "��С���о�֪����\n",
	]) );
	setup();
}

void init()
{
	object ob;

	::init();
	add_action("do_save","jiu");
	add_action("do_wei","wei");

	if ( interactive(ob = this_player()) && !is_fighting() )
	{
		 remove_call_out("wangwang");
		 call_out("wangwang", 1, ob);
	}
}

void wangwang(object ob)
{
	if (ob->query("id") == "solomon" )
		message_vision("С�����˵س���ֱҡβ��\n",ob);
	else
		message_vision("С�����˵س�����������\n",ob);
}

int do_save(string arg)
{
	this_player()->set("chanxin/save",1);
	message_vision("С�����˵س���ҡ������β��\n",this_player());
	return 1;
}

int do_wei(string arg)
{
	if (this_player()->query("chanxin/save")>=1)
	{
		this_player()->set("chanxin/save",2);
		message_vision("С�����˵س���ҡ������β��\n",this_player());
		return 1;
	}
	else
	{
		message_vision("С�����˵س���ҡ������β��\n",this_player());
		return 1;
	}
}
