// Room: /d/yanziwu/path15.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "红泥小路");
	set("long", @LONG
这是条红泥小路，在山青水绿的江南，到处都能看到这种红色的泥
土。走在红泥路上，衬托着路边的青草越发绿得可爱。路西紧靠着藕韵
塘岸，一溜的杨柳枝条点击着水面，带来无限旖旎情愫。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast"  : __DIR__"path14",
		"south"      : __DIR__"hongxia1",
	]));
	set("coor/x", 1250);
	set("coor/y", -1240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}