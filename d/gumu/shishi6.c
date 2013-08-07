// Room: /d/gumu/shishi6.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIC"ʯ��"NOR);
	set("long", @LONG
����Ҳ������֮������̧ͷ�����������Ҷ����������д�����ּ�
���ţ��㿴��һ�ᣬ���������ѽ⡣�Ҷ����Ͻǻ���һ��ͼ�������书
�޹أ�����ϸ���������Ƿ���ͼ��ʯ�����·������������(down)�ߡ�
LONG	);
	set("item_desc", ([
		"down" : HIB"�ں����ģ��������С�\n"NOR,
	]));
	set("exits", ([
		"up" : __DIR__"shiguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -40);
	set("coor/z", 60);
	setup();
}

void init()
{
	add_action("do_look", "look");
	add_action("do_look", "kan"); 
	add_action("do_walk", "walk");
	add_action("do_walk", "zou");
}

int do_look(string arg)
{
	object me=this_player();

	if ( arg =="map")
	{
		write(HIY"���������Ƿ�ͼ�����в��ɴ�ϲ��ԭ���ǻ�����ǳ�Ĺ���ص���\n"NOR);
		me->set_temp("map", 1);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_walk(string arg)
{ 
	object me=this_player();

	if ( arg =="down")
	{
		if(!me->query_temp("map"))
			return notify_fail("������������ߣ�������ԥ������������˽š�\n");
		write(HIM"�㶫ת���䣬Խ��Խ�͡�ͬʱ���½�����ʪ��������Լ��ȥ����������\n���������һ�ᣬ��·�涸�����Ǳ�ֱ���¡��½���ԼĪ���ʱ������\n·��ƽ�ˣ�ֻ��ʪ��ȴҲ���أ�������������������ˮ����·��ˮû��\n�ס�Խ��ˮԽ�ߣ����ȶ������������롣\n"NOR);
		me->delete_temp("map");
		me->move(__DIR__"anhe1");
		return 1;
	}
	return notify_fail("����ʯ����������ȥ����֪����Ǻã�\n");
}
