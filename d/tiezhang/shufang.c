// Room: /d/tiezhang/shufang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�鷿"NOR);
	set("long", @LONG
���������ư��ڵ��鷿���Դ��ϴ������Ϲٽ������ź�����鷿
��������������ǽ�ڵ���������ǻҳ�������Ҳ��һ����������סһ��
�࣬������϶���Ҳ�����ж��ٹ���������
LONG	);
	set("exits", ([ 
		"south"      : __DIR__"zoulang2",
	]));
	set("objects", ([ 
		BOOK_DIR"spear_book" : random(2),
	]));
	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	
}
