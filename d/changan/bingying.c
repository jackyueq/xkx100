// /d/changan/bingyin.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����ǳ����ؾ�פ���أ�һ�Թٱ����ڲ���������øϽ��߿�����
Ȼ����㰲�������ؽ����οɲ��Ǻ���ġ�
LONG );
	set("exits", ([
		"west" : __DIR__"northroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : random(2) + 1,
		"/d/city/npc/bing" : random(2) + 1,
	]));
	set("outdoors", "changan");
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
