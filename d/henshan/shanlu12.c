// Room: /d/henshan/shanlu12.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣������ɽ��·��������������ˮ�졣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"    : __DIR__"shanlu11",
           "eastup"  : __DIR__"shuiliandong",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -290);
	set("coor/y", -1080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
