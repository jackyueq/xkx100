// Room: /yangzhou/wangchunlou2.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","����¥");
	set("long",@LONG
����¥¥�Ͼ�Ϊ��Ŵ���жȥ���¶̨��Ϊ���¼Ѵ�������֣��
��ī��������¥���ң����������ž�����׼������(lian)��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        ��        ˫
        ��        ��
        ��        ��
        ��        ��
        ��        ��
\n"NOR,
	]));
	set("objects", ([
		"/d/city/npc/lady2" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"wangchunlou",
	]));
	set("coor/x", -30);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
