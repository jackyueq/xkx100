// Room: /d/baihuagu/baihuagu.c
// Last Modified by Winder on Mar. 5 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"�ٻ�����"NOR);
	set("long", 
HIG"ֻ������̺죬��ɽ���壬�ʵ��׷ɣ�Ⱥ�����衣����������أ�
������Դ��Ҳ������ˡ�\n"NOR);
	set("outdoors", "baihuagu");
	set("exits", ([
		"out"   : __DIR__"huagu7",
		"south" : __DIR__"baihuagu1",
		"north" : __FILE__,
		"west"  : __FILE__,
		"east"  : __FILE__,
	]));
	set("objects", ([
	]));
	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -360);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
