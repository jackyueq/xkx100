// /d/taohuacun/shiji1.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ�����ֻ�뿴
��(list)��ʲô����ģ���������(buy) ���ֻ�ȥ��������һĶ����
��Ҳ�Ͳ����ˡ�
LONG
	);
	set( "exits", ([
		"north" : __DIR__"shiji2",
		"west" 	: __DIR__"shiji4",
		"east" 	: __DIR__"shiji5",
		"south"	: __DIR__"shijigate",
	]));
	set("objects", ([
		__DIR__"npc/cainong" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -100);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}