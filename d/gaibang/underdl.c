// Room: /d/gaibang/underdl.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ͽֱ�");
	set("long", @LONG
���Ǵ�����д�ͽֱ��ϵĴ������������������õģ������˸���
�������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"       : "/d/dali/dahejieeast",
		"northeast" : __DIR__"dlandao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -39900);
	set("coor/y", -71030);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}