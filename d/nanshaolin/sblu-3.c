// Room: /d/nanshaolin/sblu-3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
һ����ʯ�̳ɵ�С·�����������������������Ѷ�ȥ��ʯ·�Ͼ���
��㳾��������������������ɨ��·�����������Ĵ��̵�������΢��
������ҡҷ��ɳɳ���졣�������ܽ�Ľ�̳��
LONG );
	set("exits", ([
		"south"     : __DIR__"sblu-2",
		"northwest" : __DIR__"jietan1",
		"northeast" : __DIR__"jietan2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6140);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

