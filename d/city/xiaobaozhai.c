// Room: /city/xiaobaozhai.c

inherit ROOM;

void create()
{
	set("short", "С��ի");
	set("long", @LONG
��Զ�󽫾��ҹٳ��Ӻ󣬴����߸����ţ���������͵͵�������С
��ի����Щ����������Ľ����鱦���չ�һЩ�Ŷ���������ʵ���˲���
��ơ�
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("objects", ([
		"/quest/weixiaobao" : 1,
	]));
	set("exits", ([
		"east"   : __DIR__"shilijie1",
	]));

	set("coor/x", 0);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}