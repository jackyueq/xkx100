// /d/beihai/shulin.c
// Last Modified by winder on May. 22 2002
inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
���Ǻ���һƬС�����֣����������������һ��С������������
�����쿪ȥ��������Ƭ���־Ϳ��Կ���������ǰ�����ˡ�
LONG
	);
	set("exits", ([
		"west"  : __DIR__"qianmen",
		"north" : __DIR__"dongmen",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
