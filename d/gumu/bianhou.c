// Room: /d/gumu/bianhou.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIB"�Һ�"NOR);
	set("long", @LONG
������ǹ�Ĺ�����Ҷ�֮�󣬺������ʲô���������������ʯ��
��������һƬ�λơ������ƺ�����һ��ͨ����
LONG	);
	set("exits",([
		"down"  : __DIR__"zhongting",
		"enter" : __DIR__"mishi1",
	]));
	set("objects",([
		__DIR__"obj/silverkey" : 1,
	]));
	set("coor/x", -3200);
	set("coor/y", 10);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

