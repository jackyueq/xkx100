// wg_xutang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ѧ��");
	set("long", @LONG
����������ڵ�һ��Сѧ�ã������������ʶ�������һ����������
������Ľ��ţ�������������Ӻ����ӡ�
LONG);
	set("exits", ([
		"west" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_fang" : 1,
		__DIR__"npc/wg_hengshandizi" : 1,		
	]) );
	set("coor/x", 51);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


