// /d/taohuacun/shiji2.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ����������
�룬�����ͷ�е�ʲô��ˮ�����Ϳ��Ժ������ũ��(change)�㶫����
ȥ���
LONG
	);
	set( "exits", ([
		"south"	: __DIR__"shiji1",
		"north" : __DIR__"shiji3",
		"west" 	: __DIR__"shiji6",
		"east" 	: __DIR__"shiji7",
	]));
	set("objects", ([
		__DIR__"npc/guanong" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -100);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}