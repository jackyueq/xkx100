// Room: /d/henshan/shanlu11.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣������ɽ�ǳ�۷塣����ԶԶ���Կ�����ɽ���֮
һ���ϸǷ��ˡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westup"  : __DIR__"chidifeng",
           "east"    : __DIR__"shanlu12",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
