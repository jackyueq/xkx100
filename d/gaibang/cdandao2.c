// Room: /d/gaibang/cdandao2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
	set("exits", ([
		"southwest" : __DIR__"undercd",
		"northeast" : __DIR__"cdandao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6000);
	set("coor/y", -2000);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
