// Room: /d/songshan/tianzhongge.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "���и�");
	set("long", @LONG
���и���������Ĵ��ţ�ԭ�ƻ��и������йŰ��������꣬��ʯ
���ٰ���������ǰʯ���٣����ƹ��ӡ���������ɽ�ĳ���̫���ڡ�
LONG );
	set("outdoors","songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
