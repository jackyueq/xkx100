// Room: /d/quanzhou/shanlu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�
������Ҷ������ϡ�ɡ������ౡ�����ϰϰ��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"southdown" : __DIR__"shanlu3",
		"northup"   : __DIR__"huruquan",
		"westup"    : __DIR__"liandanshi",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6410);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
