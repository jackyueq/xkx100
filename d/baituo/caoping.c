// Room: /d/baituo/caoping.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","��ƺ");
	set("long", @LONG
������һ�鷼��ƺ���̲����𣬺������裬���˸е���⡣����ż
��Ҳ�������˻��ߡ�
LONG	);
	set("exits", ([
		"west" : __DIR__"shijie",
	]));
	set("objects" , ([
		__DIR__"npc/caihuashe" : random(2),
	]));
	set("outdoors", "baituo");
//	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
