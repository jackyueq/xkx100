// shanlu4.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����������С·�ϣ�������;ɽ����Ӱ��������У���ʯ�߲���
�����е��ػ��泩�����ϱ㵽�������á����¾͵���������
LONG);
        set("exits", ([
            "westup"   : __DIR__"faxisi",
            "eastdown" : __DIR__"shanlu5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
	set("coor/x", 2610);
	set("coor/y", -1600);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
