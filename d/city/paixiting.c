// Room: paixiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "��Ϸ��");
	set("long", @LONG
��������Ϸ������Χ�ĸ���������Ŷ������ţ������������ơ���
��������񫡣�������������ţ��Ϳ�������������ֽ�����������ϵ���
����������ż��������������
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yapairoom",
		"east"  : __DIR__"pai9room",
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"gongzhuroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
