//Room: /d/huashan/shop.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
�����ǻ�ɽɽ����һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο͵�
Ǯ��
LONG );
	set("exits", ([
		"east" : __DIR__"square",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	set("coor/x", -870);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
