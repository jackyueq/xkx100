// Room: /d/quanzhou/chenghuangxiang1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��������խ����ʯС·��������ľ�β����ɭ�䡣
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"northroad2",
		"northwest" : __DIR__"chenghuangmiao",
	]));
	set("coor/x", 1850);
	set("coor/y", -6460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
