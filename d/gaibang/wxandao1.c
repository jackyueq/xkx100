// Room: /d/gaibang/wxandao1.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
	set("exits", ([
		"north" : __DIR__"undertre",
		"south" : __DIR__"wxandao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 100);
	set("coor/y", 500);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
