// road8.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
������������򶫱ߺ����ϱߡ������߱����ϱ�ʯɽ��
LONG);
        set("exits", ([
            "east"      : __DIR__"road9",
            "northup"   : __DIR__"baoshishan",
            "southwest" : __DIR__"road7",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4100);
	set("coor/y", -1440);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
