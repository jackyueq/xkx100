// lengquanting.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ȫͤ");
        set("long", @LONG
��Ȫͤ�������������ߣ�ͤ��СϪ�峺���ף�����������������
����ͤ�߾��Ƿ����塣ͤ��������һ����(duilian)��
LONG);
        set("exits", ([
            "east" : __DIR__"lingyinsi",
        ]));
        set("item_desc", ([
            "duilian" :
"Ȫ          ��
��          ��
��          ��
ʱ          ��
��          ��
��          ��
��          ��\n"
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
	set("coor/x", 2490);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
