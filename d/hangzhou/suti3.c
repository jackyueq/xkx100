// suti3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
��������ѩ�����У���������̤ѩ�۾����ӵ��ϼ�ĿԶ����ֻ��
�����������֡������Ƕ����ţ�������ѹ���š�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti2",
            "south"     : __DIR__"suti4",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4080);
	set("coor/y", -1470);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
