// Room: /d/yanziwu/bridge2.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "к����");
	set("long", @LONG
������ˮ�����ӷ��������£���к����������̫���С�ˮ��������
�£��������죬��������ˮ�������������һ�㣬�����Ź����������
ˮ�졣վ�����ϣ��������ġ�к�񡱶��֣��·��������ߵĲ�����ˮ��
�������޻ڵ��껪��
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"path11",
		"west"  : __DIR__"path16",
	]));
	set("coor/x", 1230);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}