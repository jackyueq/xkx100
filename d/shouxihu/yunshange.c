// Room: /yangzhou/yunshange.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","��ɽ��");
	set("long",@LONG
��ɽ��������麣�����ڵ��治��һ�ɣ��м���̨�����£�����
��������κ������(lian)��
LONG );
	set("item_desc", ([
		"lian" : HIG"
        ��        ��
        ǰ        ��
        ��        ��
        ɫ        ��
        ��        ��
        ��        ��
        ��        ��
\n"NOR,
	]));

	set("exits", ([
		"south"     : __DIR__"lianxingsi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}