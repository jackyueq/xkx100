// Room: /d/yanziwu/path17.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����������С·��·��ֲ��һ�����۵���ݣ�·��������������·
���������ԣ����Կ����̲�̫���ϵ��淫����ɫ�淫�£������������
���㣬���Ʈ�������������
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"ouxiang1",
		"east"      : __DIR__"path16",
	]));
	set("coor/x", 1210);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}