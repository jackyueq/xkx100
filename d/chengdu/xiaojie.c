// Room: /d/chengdu/xiaojie.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����ʯ���̳ɵ�С�֣�·��ǳ��ɾ��������߿��������õ�
������������Լ��������ͤ��һ�ǡ�
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"north"     : __DIR__"dongjie2",
		"southeast" : __DIR__"xiaojie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

