// yuhuangsj.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
ֻ�����ϵ�ɽ·�������ӡ�ɽ·����һ��С����ͤ������������
��ͤ��Ъ�š���������һ����ʯ�������������ɽ��·��
LONG);
        set("exits", ([
            "northeast" : __DIR__"road15",
            "westup"    : __DIR__"shanlu7",
        ]));
        set("objects", ([
            __DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4120);
	set("coor/y", -1700);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
