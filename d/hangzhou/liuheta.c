// liuheta.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��������ɽ����������������֮ǰ�������������������������͡�
֮����֮��ҵ����ֹ�Լ�������ϡ����ǡ��죬�أ��ķ�������˼��
�����˽�����ʮ���㣬�����ķ����̽�������һ������ֻ�����塣
LONG);
        set("outdoors", "xihu");
        set("exits", ([
            "eastdown" : __DIR__"qiantang",
            "enter"    : __DIR__"liuhe1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 3900);
	set("coor/y", -1800);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
