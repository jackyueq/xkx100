// Room: /d/nanshaolin/huaishu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ǰһ�����߽�һƬ�����֣�֦ͷ����������������絴������һ
���徻����֮���ڡ�����һ��С����������ǰ����
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"west" : __DIR__"putiyuan",
		"east" : __DIR__"huaishu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

