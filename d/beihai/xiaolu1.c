// /d/beihai/xiaolu1.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�����ź���С·��·������һƬ�����֣�������Կ�����
�ϵİ������������ﲻʱ���Կ���һֻֻ����������ȥ��
LONG
	);
	set("exits", ([
		"south" : __DIR__"ximen",
		"north" : __DIR__"xiaolu2",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
