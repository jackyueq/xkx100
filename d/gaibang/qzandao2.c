// Room: /d/gaibang/qzandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
	set("exits", ([
		"southeast" : __DIR__"underqz",
		"northwest" : __DIR__"qzandao1",
	]));
	set("objects",([
		FOOD_DIR+"jitui" : 3,
		LIQUID_DIR+"jiudai" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 1000);
	set("coor/y", -500);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
