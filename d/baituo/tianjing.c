#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"�쾮"NOR);
	set("long", @LONG
ת��һ��ʯ�ڣ������ǰ��Ȼһ����ԭ�������Ǹ���Ȼ�γɵ��쾮��
��Լ��ʮ���ɼ�����ͷ��һ��Բ�����������Ǵ�������������ġ�һ��
������ɽ����������Ա߳����˸��ֻ��ݣ����м��Ź���������һ��
�������㷢����һֻ�����ĵ�������վ��Ϫ�߿����㡣
LONG);
	set("resource/water", 1);
	set("objects", ([
		__DIR__"npc/he" : 1,
		"/clone/book/bt_book4" : 1
	]));	
	set("exits", ([
		"out" : __DIR__"midao4",
	]));
	set("outdoors", "baituo");
	set("grass_count",8);
	set("guo_count",10);
	set("coor/x", -49950);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	this_player()->set_temp("find_times", 20);
	add_action("do_find", "find");
	add_action("do_zhai", "zhai");
}

int do_find()
{
	object me, ob;
	int luck;
	me = this_player();
	ob = new(__DIR__"obj/grass");
	luck = (int)me->query_int() * (int)me->query_con() / 5;
	luck = luck + (int)me->query("kar") / 3 - 30;
	message_vision("$N�������ӣ��ڲݴ�����ϸ��Ѱ����ʲô��\n", me);
	if ( me->query_temp("find_times") == 0 )
	{
		message_vision("$Nһ��С�ı��Ӳݸ���һ���˿ڣ���Ѫֱ����\n",me);
		me->set_temp("find_times", random(20));
		me->receive_wound("qi", 65);
		return 1;
	}
	me->add_temp("find_times", -1);
	if (random(luck) > 115 && query("grass_count") >= 1)
	{
		add("grass_count", -1);
		ob->move(me);
		message_vision("$N���ס���һ����ԭ��������һ��ϳ��ݡ�\n", me);
	}
	return 1;
}

int do_zhai(string arg)
{
	object me = this_player();
	if (arg == "guo" && me->query_dex() > 25 && query("grass_count") >= 1)
	{
		message_vision("$N˳�ִӹ�����ժ��һ�����ӡ�\n", me);
		new(__DIR__"obj/guo")->move(me);
		add("grass_count", -1);
		return 1;
	}
	return notify_fail("��Ҫժʲô��\n");
}
