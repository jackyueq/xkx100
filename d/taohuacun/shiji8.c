// /d/taohuacun/shiji8.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ������С��
��ʲô�����ģ�
LONG
	);
	set( "exits", ([
		"east"	: __DIR__"shiji3",
		"south"	: __DIR__"shiji6",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -110);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}