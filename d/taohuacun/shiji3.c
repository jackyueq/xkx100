// /d/taohuacun/shiji3.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ����������
�룬�����ͷ�е�ʲô��ˮ�����Ϳ��Ժ�����ⷷ��(change)�㶫����
ȥ���
LONG
	);
	set( "exits", ([
		"south"	: __DIR__"shiji2",
		"west"	: __DIR__"shiji8",
		"east"	: __DIR__"shiji9",
	]));
	set("objects", ([
		__DIR__"npc/roufan" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -100);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}