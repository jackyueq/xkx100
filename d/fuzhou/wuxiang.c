// Room: /d/fuzhou/wuxiang.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��СС���á�
LONG );
	set("exits", ([
                "south" : __DIR__"shulin",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1880);
	set("coor/y", -6250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
