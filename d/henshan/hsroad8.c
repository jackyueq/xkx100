// Room: /d/henshan/hsroad8.c �ּ��
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "�ּ��");
	set("long", @LONG
������һ���ּ�С���������������ѡ�����������һ������·����
��ĵ�·Ҫ��һЩ��
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northwest" : "/d/yueyang/nanmen",
		"south"     : __DIR__"hsroad7",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

