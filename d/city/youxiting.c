// Room: youxiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ�����ַǷ����������������ӣ����е�ߺ�ȣ����ɹ�����
��������ͽ�����ͺ��ĳ���������������ռ䡣�����û��Ȥ��������
������������ġ�
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"doujiroom",
		"east"  : __DIR__"saiguiroom",
		"north" : __DIR__"zoulang2",
		"south" : __DIR__"yaqianroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
