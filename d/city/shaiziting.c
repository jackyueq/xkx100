// Room: shaiziting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƕĳ����������������˽��˳��ģ����յ��ſ�����ʱ�򣬱�
�����ﴫ��һ�����������ӵ�������
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("exits", ([
		"west"      : __DIR__"shaiziroom",
		"east"      : __DIR__"yacairoom",
		"south"     : __DIR__"duchang",
		"north"     : __DIR__"daxiaoroom",
		"northeast" : __DIR__"dahua",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
