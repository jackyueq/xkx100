// /d/taohuacun/jishi9.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�м�" );
	set( "long", @LONG
�����м��У������ͷ�ܶ���ߺ�Ƚ���֮�������ڶ����������
�룬�����ͷ�е�ʲô��ˮ�����Ϳ��Ժ�����Ի���(change)�㶫����
ȥ���
LONG
	);
	set( "exits", ([
		"west"	: __DIR__"shiji3",
		"south"	: __DIR__"shiji7",
	]));
	set("objects", ([
		__DIR__"npc/liehu" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}