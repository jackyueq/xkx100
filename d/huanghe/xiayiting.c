// Room: /huanghe/xiayiting.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���ǻƺӰ����µĴ��������Ϲ��š��������������Ҷ���￿
�����Ϸ���һ�Ż�Ƥ���Σ����߰����ż�����ľ���Σ��ǳ������ɡ�
ǽ�ϸ�ӹ���ŵع��˼��������鷨��
LONG );
	set("exits", ([
		"east"  : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/sha" : 1,
		__DIR__"npc/peng" : 1,
		__DIR__"npc/liang" : 1,
	]));
	set("coor/x", -2020);
	set("coor/y", 520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}