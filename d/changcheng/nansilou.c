// Room: /d/changcheng/nansilou.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", WHT@LONG
һ������ʮ�ֶ��͵�����¥��������֪���ˡ��������ǷǺú�����
��ζ�ˡ�ƣ��֮�࣬�ٷ���ȻԶ������������ʮ�ﳤ�Ĺع����ƺ�����
��ߡ�����Ⱥɽ����֮�⣬���Ǿ����ˡ�
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"eastdown"  :__DIR__"changcheng22",
		"northdown" :__DIR__"beisilou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 2000);
	set("coor/y", 5000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}