// Room: /d/baihuagu/huagu3.c
// Last Modified by Winder on Mar. 5 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"�ٻ���"NOR);
	set("long", 
HIR"�����˴�����ͻȻ��ǰһ�������������ȣ���׺�Ż����ϣ�
��ƻ�׵��ʻ������ǻ���һ�����硣������һ���������������ޡ�\n"NOR);  
	set("outdoors", "baihuagu");
	set("exits", ([
		"west" :__DIR__"huagu2",
		"north":__DIR__"huagu3",
		"east" :__DIR__"huagu2",
		"south":__DIR__"huagu4",
	]));
	set("objects", ([
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -360);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
