// /d/xiakedao/lin5.c
// Modified by Zeratul Jan 11 2001

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֣������������һ����һ�߽�������·���ʧ�˷���
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "east" : __DIR__"lin4",
                "west" : __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __DIR__"lin6",
        ]));
        set("objects", ([
            __DIR__"npc/yezhu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
