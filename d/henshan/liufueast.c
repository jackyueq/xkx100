// liufueast.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "���᷿");
	set("long", @LONG
����Ƕ��᷿���������øɸɾ���������¶�������̵�֦Ҷ����
����һ����Ⱦ���������źܴ�����ש��һ��ҳ�Ҳ��մ��
LONG);
	set("exits", ([
	    "west"   : __DIR__"liufudating",
	]));
	set("objects", ([
		__DIR__"npc/liufuren" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -390);
	set("coor/y", -1170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
