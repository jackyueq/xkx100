// Room: /d/hengshan/jijiaoshi.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����ʯ");
	set("long", @LONG
����������࣬��һ���������ʯͷ���Ƽ���ʯ����֮����������
�����������������峿�û�������ɽ�Ȼ�������Ⱥ���������ͳơ���
��������
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"beiyuemiao",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 3170);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

