// Room: /d/nanshaolin/fota3.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������������棬�����������ž���������Լ����������һ�����
�ҳ��������ܲ��ķ��衣��Ȼһ����粻֪���Ĵ��˹������㲻������
�����䡣
LONG );
	set("exits", ([
		"down"     : __DIR__"fota2", 
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

