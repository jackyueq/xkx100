// Room: /huanghe/shulin1.c
// Java. Sep 21 1998

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�������Ұ
�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ�����������һ������(paizi)��
LONG );
	set("exits", ([
		"west"  : __DIR__"shulin2",
		"east"  : __DIR__"caodi2",
		"north" : __DIR__"shulin3",
	]));
	set("item_desc", ([
		"paizi" : HIR"\n�ǻƺӰ�����    �����ɱ����\n\n"NOR,
	]));
	set("objects", ([
		"/d/shenlong/npc/dushe" : 1,
		"/d/hangzhou/obj/shuzhi" : 1,
	]));
	set("outdoors", "huanghe");
	set("coor/x", -210);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}