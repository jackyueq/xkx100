// /kaifeng/zhongyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��Ժ��Ϊǰ�������֣�Ժ�ӵ������������Ƹ��������߲㣬�����
�������ơ�ǰ�߲��ֳ��м���е��⣬�����ǻ��ԣ�����һ�øߴ����
���������������ʯ��ͨ����۱���ϱ����������������ի����
������ԡ�ҡ�
LONG
	);
	set("objects", ([
		__DIR__"npc/obj/tiefutu" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"tianwang",
		"north" : __DIR__"daxiong",
		"east"  : __DIR__"chufang",
		"west"  : __DIR__"yushi1",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
