// /d/taohuacun/shiji7.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ�����������
����������㲻�������ʲô��
LONG
	);
	set( "exits", ([
		"west"	: __DIR__"shiji2",
		"south"	: __DIR__"shiji5",
		"north"	: __DIR__"shiji9",
	]));
	set("objects", ([
		__DIR__"npc/flowerg" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}