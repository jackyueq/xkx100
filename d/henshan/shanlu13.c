// Room: /d/henshan/shanlu13.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣�����������������ˣ��߸ߴ������������ľ��Ǻ�
ɽ���֮һ��ܽ�ط塣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northeast"  : __DIR__"nantian",
           "southeast"  : __DIR__"shanlu5",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1030);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
