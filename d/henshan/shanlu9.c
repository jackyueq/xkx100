// Room: /d/henshan/shanlu9.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣�ϱ�����̨�£�����ͨ�������¡�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"  : __DIR__"nantaisi",
           "northup"  : __DIR__"fuyansi",
        ]));
        set("objects", ([
            "/clone/medicine/vegetable/jinyinhua" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -330);
	set("coor/y", -1080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
