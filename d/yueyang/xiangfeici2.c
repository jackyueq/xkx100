// Room: /d/yueyang/xiangfeici2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������ǰ��");
	set("long", @LONG
ǰ������������������ĵڶ��������佫���أ��������᷿������
�������ǽ���ϵ����������ң����Ǹ���ͬ����Ϊ���ٵ���˼��
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"xiangfeici1",
		"north" : __DIR__"xiangfeici3",
	]));
	set("coor/x", -1660);
	set("coor/y", 2320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
