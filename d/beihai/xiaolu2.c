// /d/beihai/xiaolu2.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�����ź���С·��·������һƬ�����֣��ϵİ�����������
�ﲻʱ���Կ���һֻֻ����������ȥ�������������Կ���һ��ͤ�ӵ�һ
�ǡ�
LONG
	);
	set("exits", ([
		"east"      : __DIR__"wulong",
		"south"     : __DIR__"xiaolu1",
		"northeast" : __DIR__"dukou1",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
