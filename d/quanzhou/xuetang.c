// Room: /d/quanzhou/xuetang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ѧ��");
	set("long", @LONG
���ǳ����һ��ѧ�ã����е��ӵܱ��ڴ��ϿΡ�ѧ����Ĺ������
�����鼮������������������Ȫ�ݵ�ŷ��ղ������
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"guitangxiang",
	]));
	set("objects", ([
		__DIR__"npc/ouyangzhan" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
