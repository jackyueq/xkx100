// Room: /d/nanshaolin/shanlu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
��Ŀ��ȥ��������Ƭ����β�ɡ������������ƺ�������һ��������
���⵽�����ø���������ֻ�ڵ������°߲�����Ӱ��������Զ�����
һ����������֦���������������·�����֣�·�涼������ʯ�塣
LONG);

	set("exits", ([
		"southdown" : __DIR__"ting",
		"north"     : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6340);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



