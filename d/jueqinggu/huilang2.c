// Room: /d/jueqinggu/huilang2.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����ŵĻ��ȣ����滭���������˵��黭��
LONG
	);

	set("exits", ([
		"south"     : __DIR__"xiufang",
		"northeast" : __DIR__"huilang1",
		"north"     : __DIR__"danfang",
	]));
	set("objects", ([
		__DIR__"npc/puren1" : 1,
	]));
 	set("coor/x", -560);
	set("coor/y", -380);
	set("coor/z", 20);
	setup();
	 
}
int valid_leave(object me, string dir)
{
	  if (!me->query("jqg_pass")&&
	  present("pu ren", environment(me)) &&
	  (dir=="north"))
	  return notify_fail("������ס��˵��������û������ͬ�⣬���������롣\n");
	  return ::valid_leave(me, dir);
}
