// Room: /heizhao/shanlu8.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����ѭ�Ŷ�·���룬��·�Ѿ�ʮ����խ����Щ�ط������ϲ�
����·�ˡ�·��ɽ����죬ɽ������������ġ�
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu7",
		"westup"    : __DIR__"shanlu9",
	]));
	set("coor/x", -5010);
	set("coor/y", -1290);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}