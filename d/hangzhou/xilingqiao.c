// xilingqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ν��ɽ��������������ŵĶ��ϱ��ǹ�ɽ����������һ
����ʯ�����
LONG);
        set("exits", ([
            "southeast" : __DIR__"gushan",
            "north"     : __DIR__"road7",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4090);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
