// Room: /yangzhou/chunboqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
С������һ��ľ�ƹ��ţ����������һ��룬������������¥ǰ�϶�
С��������������¥��ͨ��
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"west" : __DIR__"taohuawu",
		"east" : __DIR__"siqiaoyanyu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}