// /d/beihai/xitian.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�峯ʱ�����ڽ̽�������Ҫ������������ʽ����������С���졢
�����¡������졢��������ȡ����������Ͼ���ȥ�����Ķɿڡ�
LONG
	);
	set("exits", ([
		"west"      : __DIR__"jiulongbi",
		"southwest" : __DIR__"dukou1",
		"northeast" : __DIR__"jingqing",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
