// dxbaodian2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���۱���");
        set("long", @LONG
��������һ�����������������ж�ʮ������ķ��񣬴�����
����ʮ���κ����񣬵�������̬����Ĵ�С����һ����ʮ����
LONG);
        set("exits", ([
                "out"     : __DIR__"dxbaodian1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 2500);
	set("coor/y", -1370);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}