// road17.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
������������ϱ����ߣ������ǻ���Ȫ��������һ��ɽ·��
LONG);
        set("exits", ([
            "north"     : __DIR__"road18",
            "south"     : __DIR__"qiantang",
            "west"      : __DIR__"hupaoquan",
            "east"      : __DIR__"yuhuangshan",
        ]));
        set("objects", ([
            __DIR__"npc/tiao-fu" : 1,
            __DIR__"npc/chuyuan" : 1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4000);
	set("coor/y", -1700);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
