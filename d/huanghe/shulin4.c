// Room: /huanghe/shulin4.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�������Ұ
�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );
	set("exits", ([
		"northwest"  : __DIR__"shulin5",
		"east"       : __DIR__"shulin3",
		"south"      : __DIR__"shulin2",
	]));
	set("objects", ([
		"/d/baituo/npc/fox" : 1,
	]));
	set("outdoors", "huanghe");
	set("coor/x", -220);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}