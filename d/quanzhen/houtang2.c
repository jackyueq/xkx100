// houtang2.c ���ö���
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ö���");
        set("long", @LONG
������ȫ��̵���ƽ�������书�ĵط�������ò������ھ���
Ҫ���������䣬����������Ҳȫ������ǽ��ȥ�ˣ������ڳ���һ��Ƭ
�յ�����
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtang3",
                "west" : __DIR__"houtang1",
                "south" : __DIR__"wuchang1",
                "north" : __DIR__"liangong",
        ]));

	set("coor/x", -2750);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}