// shanlu8.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ����ľï�ܣ������������ﻹ���������ɡ������߱㵽�˻�������
�ϱ�������ɽ��·��
LONG);
        set("exits", ([
            "south"     : __DIR__"road7",
            "north"     : __DIR__"huanglongdong",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4090);
	set("coor/y", -1430);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
