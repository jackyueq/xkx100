// Room: /d/xiangyang/caodi2.c
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
		"east"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"npc/menggubing" : 2,
	]));
	set("coor/x", -510);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}