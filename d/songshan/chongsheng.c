// Room: /d/songshan/chongsheng.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "��ʥ��");
	set("long", @LONG
��ʥ��ǰ�����������������ˣ��ߴ����������ȭ��ŭĿͦ�أ�
�����۽����򱱾������������ĵ�����������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"tianzhongge",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
