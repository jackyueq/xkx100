// Room: /d/henshan/yushulou.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
����¥Ϊ��������������֮�����������ͣ��ʹ��־裬����������
���ۡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"jiayingmen",
           "north"  : __DIR__"dadian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1140);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
