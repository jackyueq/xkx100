// Room: /d/nanshaolin/huaishu4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ǰһ�����߽�һƬ�����֣�֦ͷ����������������絴������һ
���徻����֮���ڡ�����һ��С����������ǰ����
LONG
	);
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"  : __DIR__ "stoneroad1",
		"west"  : __DIR__ "slyuan",
		"north" : __DIR__ "huaishu5",
		"south" : __DIR__ "huaishu2", 
	]));
	set("coor/x", 1800);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

