// Room: /huanghe/shulin3.c
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
		"west"  : __DIR__"shulin4",
		"south" : __DIR__"shulin1",
		"north" : __DIR__"tiandi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -210);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}