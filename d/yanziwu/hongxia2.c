// Room: /d/yanziwu/hongxia2.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"��ϼ��¥"NOR);
	set("long", @LONG
��ϼ¥�ϳ��赭�����¡�һ�����û����һ��ʢ���Ĳ軨������һ
��ľ����д���ǣ�������ˮ���軨�ף��Ĺ�������֦�족��
LONG );
	set("exits", ([
		"down"     : __DIR__"hongxia1",
	]));
	set("objects", ([
		__DIR__"obj/chahua14" :1,
		__DIR__"npc/xiaoming" :1,
	]));
	set("coor/x", 1250);
	set("coor/y", -1250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}