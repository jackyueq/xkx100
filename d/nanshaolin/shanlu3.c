// Room: /d/nanshaolin/shanlu3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
�����Ѿ�ûʲô�����ˡ�������¡���ɽ�����ϱ�ɽ��ͨ��ɽ�⣬
ԶԶ��ȥ����һƬ��β�ɵĺ��󡣱���ɽ�����Ƭ�Ľ�������ɽ���
�ô�һƬ���֡�����·�����֣�·�涼������ʯ�塣
LONG);

	set("exits", ([
		"south" : __DIR__"shanlu2",
		"north" : __DIR__"shifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6330);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



