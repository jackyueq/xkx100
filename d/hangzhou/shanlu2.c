// shanlu2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����������Ǻܿ��ɽ·�ϣ�ֻ�����Է�����������ɫ���ˡ�һ
��СϪ��·������������Ϫ����һũ�ҡ�ɽ��С����ʹ������������
֮�⡣���ϱ㵽�������á����¾��������á�
LONG);
        set("exits", ([
            "southup"   : __DIR__"fajinsi",
            "northdown" : __DIR__"fajingsi",
        ]));
        set("objects", ([
            __DIR__"npc/honghua2" : 2,
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 2600);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
