// ceting.c ����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�Ĳ������ܷ������ʵʵ��û��һ˿�ķ�϶���ڻ谵��
�ƹ��£����ѿ��������ĳ��衣
LONG	);
	set("exits", ([
		"east"  : __DIR__"mudao20",
		"north" : __DIR__"mudao19",
		"south" : __DIR__"mudao23",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

