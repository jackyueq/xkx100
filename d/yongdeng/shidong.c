// Room: /huanghe/shidong.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ɳĮ����Ȼ�γɵ�һ��ʯ�������й��߻谵����ȴʮ�ָ��
�������ż��ѵ��ݣ��ƺ��ǹ���˯��֮�ã��������������з·�������
ˮ��������һ�Ƿ���������ͷ��(skulls)��
LONG );
	set("exits", ([
		"out" : __DIR__"shamo1",
	]));
	set("item_desc", ([
		"skulls" : "һ���������������ͷ����һ�������壬���಻�٣�ǡ��
�ſŰ׹�����ͷ��\n",
	]));
	set("objects", ([
		__DIR__"npc/mei" :1,
		__DIR__"npc/chen" :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10000);
	set("coor/y", 5000);
	set("coor/z", -10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	this_player()->delete_temp("shamo/steps");
}