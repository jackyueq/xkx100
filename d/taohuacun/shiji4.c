// /d/taohuacun/shiji4.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ����������
�룬�����ͷ�е�ʲô��ˮ�����Ϳ��Ժ�����㷷��(change)�㶫����
ȥ���
LONG
	);
	set( "exits", ([
		"east"	: __DIR__"shiji1",
		"north" : __DIR__"shiji6",
	]));
	set("objects", ([
		__DIR__"npc/yufan" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -110);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}