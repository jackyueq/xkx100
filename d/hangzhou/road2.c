// road2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
���������ºͷ����塣�����������á�
LONG);
        set("exits", ([
                "southup"   : __DIR__"shanlu1",
                "southwest" : __DIR__"road1",
                "northeast" : __DIR__"road3",
        ]));
        set("objects", ([
           __DIR__"npc/xianghuo" : 1,
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 2600);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
