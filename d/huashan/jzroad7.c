// Room: /d/huashan/jzroad7.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ͱ�");
	set("long", @LONG
�������ͱڱߵ�С·�ϡ�һ�������ܵĴ��֣����ȴ�Ǽ���Ķ��ڡ�
ɽ������������Ҫ���������ȥ��
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"eastdown" : __DIR__"jzroad6",
		"southup"  : __DIR__"shangu",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);

	set("coor/x", -930);
	set("coor/y", 190);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
