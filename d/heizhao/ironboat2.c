// Room: /heizhao/ironboat2.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ�Һ������С�������з����������������ۺ�С����ֻ
�ܳ������ˡ�
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("coor/x", -5020);
	set("coor/y", -1240);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}