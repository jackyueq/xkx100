// Room: /d/jiaxing/yanyu.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥�����Ϻ����ĵ�һ��С���ϡ��Ϻ����겻�ϵ�ˮ����������
���������ɵġ�¥���Ǽҷ��ꡣ
LONG );
	set("outdoors", "jiaxing");
	set("exits", ([
		"up"    : __DIR__"yanyu2",
		"north" : __DIR__"nanhu1",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1
	]));
//	set("no_clean_up", 0);
	set("coor/x", 1520);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
