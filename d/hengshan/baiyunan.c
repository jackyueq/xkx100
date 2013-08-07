// Room: /d/hengshan/baiyunan.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������Ǻ�ɽ�ɰ����֡����ڹ�����¹�������������һ�����ţ�
�ı���Ȼ����ɽ�����𽭺���û�뵽���־�Ȼ����һ����˹��
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"square",
		"north"  : __DIR__"changlang",
		"west"   : __DIR__"byawest",
		"east"   : __DIR__"byaeast",
	]));
	
	set("objects", ([
		CLASS_D("hengshan")+"/xian" : 1,
		CLASS_D("hengshan")+"/lin" : 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", 40);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
	"/clone/board/hengshan_b"->foo();
}

