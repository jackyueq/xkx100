// Room: /yangzhou/banting.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
С�Ϻ�����Ķ��ǰ�ͤ�����߶��������˿���ͤ����������������
��������ɡ��ң�����������ԭ�������(lian)��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        ��        ��
        ��        ��
        ��        ��
        ɽ        ��
        ��        ��
\n"NOR
	]));
	set("exits", ([
		"east"   : __DIR__"guanyindian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}