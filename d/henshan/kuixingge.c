// Room: /d/henshan/kuixingge.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���Ǹ�");
        set("long", @LONG
���Ǹ�����������ĵڶ�������Ϊһ������̨������Ϊ��ͤ������
��ͤ��������ڳ�Ϸ�������������ַǷ���
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"lingxingmen",
           "east"   : __DIR__"zhongting",
           "north"  : __DIR__"zhengchuan",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
