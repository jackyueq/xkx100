// Room: /d/baihuagu/bhgent.c
// Last Modified by Winder on Mar. 5 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"ããѩ��");
	set("long",
HIW"�����ǰ�ãã��һƬѩ�أ�" NOR"Զ��ɽ����͵��֡�ǰ������ԼԼ
������һ��ɽ�ȡ�������Ʈ���������󻹼�������Ļ�����\n"
	);
	set("outdoors", "baihuagu");
	set("exits", ([ 
		"south" : __DIR__"out",
		"north" : __DIR__"huagu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -380);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
