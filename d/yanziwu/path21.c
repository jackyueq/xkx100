// Room: /d/yanziwu/path21.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
С·�������ӷ��µ�ɽ��������ʱ������ˮ���䣬�ѵ��ϵ�·ʯȾ
�ɵ�������ɫ��ɽ�����������де��ɰ��֣�̧ͷ������ʱ�з���Խ��
������������һƬ���ң���ͺ�ģ������������������ɽɫ�����£�
����һ��޴�����顣
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"path22",
		"enter"  : __DIR__"dong7",
	]));
	set("coor/x", 1200);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}