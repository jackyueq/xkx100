// Room: /d/henshan/shanlu10.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣ɽ·����ͨ�򷽹��¡������������塣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastup"    : __DIR__"tianzhu",
           "westdown"  : __DIR__"fangguangsi",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/chaihu" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -360);
	set("coor/y", -1050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
