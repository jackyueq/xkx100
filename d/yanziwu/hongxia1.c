// Room: /d/yanziwu/hongxia.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"��ϼһ¥"NOR);
	set("long", @LONG
����һ���ܱ��µ�С¥��¥����һ���Ҷ���д�š���ϼ¥��������
��׭�֣�¥��ǰ�������ֵĶ��ǲ軨�������в軨�ǡ��أ�������軨
��׺��ڣ�������ʮ�ж�������ĵ����һ���������ƽ���˸����ϼ����
�ƽ�¥�ͺ�ϼ¥����ׯ���˰��˼���������
LONG );
	set("exits", ([
		"south"    : __DIR__"path7",
		"north"    : __DIR__"path15",
		"eastdown" : __DIR__"huafang",
		"up"       : __DIR__"hongxia2",
	]));
	set("objects", ([
		__DIR__"obj/chahua13" : 1,
	]));
	set("coor/x", 1250);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}