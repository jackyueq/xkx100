// Room: /d/changcheng/nroad2.c
// Last Modified by Winder on Aug. 25 2000

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ����ܵ��˲��Ǻܶࡣż���м���
���򣬴Ҵ�������ȥ����ʱ����������������߷ɳ۶���������һ·
��������·��������������������֡�������ԶԶ�ľͿ��������ϱߵ�
�����ǡ�
LONG );
        set("outdoors", "changcheng");
	set("exits", ([
		"south" : __DIR__"nroad1",
		"north" : __DIR__"juyongguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

