// Room: /d/yanziwu/path16.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����������С·��·��ֲ��һ�����۵���ݣ�·������������·��
�������ԣ����Կ����̲�̫���ϵ��淫����ɫ�淫�£��������������
�㣬���Ʈ�������������
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"bridge3",
		"west"  : __DIR__"path17",
		"east"  : __DIR__"bridge2",
	]));
	set("coor/x", 1220);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}