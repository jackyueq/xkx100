// Room: /d/gaibang/cdandao1.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
	set("exits", ([
		"southwest" : __DIR__"cdandao2",
		"northeast" : __DIR__"undertre",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -1000);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
