// /d/taohuacun/shiji6.c
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
		"east"	: __DIR__"shiji2",
		"south"	: __DIR__"shiji4",
		"north" : __DIR__"shiji8",
	]));
	set("objects", ([
		__DIR__"npc/oldman" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -110);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}