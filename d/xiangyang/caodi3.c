// Room: /d/xiangyang/caodi3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ��
���ˣ��ɹű��۳���ȥ����Ϊ��������������������š�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south"  : __DIR__"northgate2",
		"north"  : "/d/luoyang/road3",
	]));
	set("objects", ([
		__DIR__"npc/menggubing" : 2,
	]));
	set("coor/x", -500);
	set("coor/y", -300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}