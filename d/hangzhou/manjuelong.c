// manjuelong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����¤");
        set("long", @LONG
ɽ·����һ��С���䣬�������ܹ𻨳��֡�ÿ�������ʢ����
Ʈ���������Ϊ����ѩ���硱��������ˮ�ֶ�������ʯ�ݶ���
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "westup"    : __DIR__"shuiledong",
                "eastdown"  : __DIR__"shiwudong",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 2900);
	set("coor/y", -1600);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
