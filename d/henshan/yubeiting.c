// Room: /d/henshan/yubeiting.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
����Ϊ�����������ʯ���������ɣ�ʯ���������������ǧ��Ĵ�
ʯ���ϣ�������ϸ�壬��Ϊ������
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"zhengchuan",
           "north"  : __DIR__"jiayingmen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1160);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
