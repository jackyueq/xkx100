// Room: /d/yanziwu/path24.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
�������·��������������ɽ�塣���н��ߣ������ģ�ɽ��������
���棬�������ٵ�̫������ռ���������Ұ��������ƣ�Զɽ���㣬��
��Խ��Խ���ˡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"path23",
		"northup"   : __DIR__"luanyun",
		"east"      : __DIR__"tianfeng",
	]));
	set("coor/x", 1210);
	set("coor/y", -1250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}