// road13.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֶ�����һ�ҿ͵ꡣ
LONG);
        set("exits", ([
            "north"     : __DIR__"road12",
            "southwest" : __DIR__"road14",
            "east"      : __DIR__"kedian",
        ]));
        set("objects", ([
            __DIR__"npc/zhang": 1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4150);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
