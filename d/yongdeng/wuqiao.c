// Room: /huanghe/wuqiao.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ϵ�һ����Ҫ�ضΣ���ʯɽ���������أ�ʱ����Ұ
�޳�û��һ���ٵ���ɽ�����Ѷ�����
LONG );
	set("exits", ([
		"south"     : __DIR__"dacaigou",
		"northwest" : __DIR__"wuwei",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yongdeng");
	set("coor/x", -9000);
	set("coor/y", 6000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}