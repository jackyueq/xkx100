// Room: /d/wuxi/road7.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
һ��������������������������·���ߴ�����һ����Ȼ�����
�м������һЩ���������ڷ���ҡҡ�����������Ŀ���������������
���ţ�����һֱͨ��̫����������һ��С����ͨ��÷���̩����
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"road8",
		"south"  : __DIR__"road10",
		"north"  : __DIR__"qingmingqiao",
	]));
	set("coor/x", 370);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}