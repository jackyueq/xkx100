// Room: /d/nanshaolin/sblu-2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
һ����ʯ�̳ɵ�С·�����������������������Ѷ�ȥ��ʯ·�Ͼ���
��㳾��������������������ɨ��·�����������Ĵ��̵�������΢��
������ҡҷ��ɳɳ���졣�����ƺ�����΢��ˮ����������Ķ��С�
LONG );
	set("exits", ([
		"west"  : __DIR__"xiaolu5",
		"east"  : __DIR__"xiaolu1",
		"south" : __DIR__"lxting",
		"north" : __DIR__"sblu-3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



