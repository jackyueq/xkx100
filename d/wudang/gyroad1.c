// gytoad1.c ��԰С·
// by Java

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��԰С·");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ����ڹ�԰�ߵ�С·�ϡ�·����Ӣ�ͷף���
���������֣�ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ��۷�
�����ˡ����ڻ�����Ϸ���æ����ͣ�������Գ���ߴզ����
LONG );
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad13",
		"east" : __DIR__"gyroad2",
	]));
	set("objects", ([
		__DIR__"npc/jumang": 1
	]));
	set("coor/x", -1930);
	set("coor/y", -930);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "east" && objectp(present("ju man", environment(me))))
		return notify_fail(RED"��ھ���"NOR"һԾ��ס���ȥ·��\n");

	return ::valid_leave(me, dir);
}
