// Room: /d/nanshaolin/fota1.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����һ��");
	set("long", @LONG
������������棬�����������ž���������Լ����������һ�����
�ҳ��������ܲ��ķ��衣��Ȼһ����粻֪���Ĵ��˹������㲻������
��������
LONG );
	set("exits", ([
		"up"  : __DIR__"fota2", 
		"out" : __DIR__"fotaout",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

