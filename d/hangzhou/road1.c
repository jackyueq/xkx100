// road1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
����ϼ�������������������Ϸ�������ο͡����߹���СϪ��
���������ˡ��ϱ����Ϸ������·��
LONG);
        set("exits", ([
                "northwest" : "/d/jiaxing/jxnanmen",
                "northeast" : __DIR__"road2",
                "north"     : __DIR__"lingyinsi",
                "south"     : __DIR__"feilaifeng",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
	set("coor/x", 2500);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
