// zhengting.c ����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ������������Ӧ��ͣ�����ѹ�ľ֮��Ķ�����ȴ��֪��
���˰㵽����ȥ�ˡ������ж˰���һ�Ŵ�ʯ�Σ������ϰڷ���һЩʯͷ
���ɵĳ����м���һ�Ŵ�ʯ����
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao15",
		"east"  : __DIR__"mudao14",
		"north" : __DIR__"mudao11",
		"south" : __DIR__"mudao16",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

