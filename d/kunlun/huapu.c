// Room: /d/kunlun/huapu.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","����");
	set("long", @LONG
������һ��С���ԣ������˸��������滨��ݣ���ԭ�ѵ�һ����
LONG
);
	set("exits", ([ 
		"north" : __DIR__"tieqinju",
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		__DIR__"obj/flower" : 2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);

}