// Room: /d/wuxi/road10.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
һ��������������������������·���ߴ�����һ����Ȼ�����
�м������һЩ���������ڷ���ҡҡ�����������Ŀ�������������ͨ
����������ȥ�ġ������Ͼ�Ҫ��̫���ˡ�
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"road7",
		"south"   : __DIR__"road11",
	]));
	set("objects", ([
		__DIR__"npc/shusheng" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -870);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}