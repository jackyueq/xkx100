// Room: /d/chengdu/xiaojie1.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����ʯ���̳ɵ�С�֣�·��ǳ��ɾ��������߿��������õ�
������������Լ��������ͤ��һ�ǡ������и����ӵꡣ
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"east"      : __DIR__"zongzidian",
		"southeast" : __DIR__"xiaojie2",
		"northwest" : __DIR__"xiaojie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

