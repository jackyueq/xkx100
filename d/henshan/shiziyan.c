// Room: /d/henshan/shiziyan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ʨ����");
        set("long", @LONG
ʨ���Ҳ������ι�״����ʯ��ϸ�������ʨ�ӣ���Ծ���𣬸�Ф��
�ࡣ��ʨ���ң�ף�ڷ��Ѿ������ˡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southwest"  : __DIR__"nantian",
           "northup"    : __DIR__"wangritai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
