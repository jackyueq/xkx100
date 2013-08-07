// Room: /d/guiyun/jiugong3.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
inherit ROOM;
#define HERENO	3

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "�Ź��һ���");
	set("outdoors", "guiyun");
	set("exits", ([
		"west"  : __DIR__"jiugong2",
		"south" : __DIR__"jiugong6",
	]));
	setup();
}

#include "jiugong.h"
