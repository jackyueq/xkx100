// changyinge.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǹ�������Ϸ̨, ÿ����ںͻ�������, �ۻʺ����������￴
Ϸ. ƽ����ż��̫��Ҳ��������ϼ����ӿ���.
LONG
	);
	set("exits", ([
		"west"  : __DIR__"yangxin2",
		"south" : __DIR__"ningshougong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}