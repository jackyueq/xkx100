// Room: /d/baihuagu/baihuagu2.c
// Last Modified by Winder on Mar. 5 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"�ٻ�����"NOR);
	set("long", 
HIG"ֻ������̺죬��ɽ���壬�ʵ��׷ɣ�Ⱥ�����衣����������أ�
������Դ��Ҳ������ˡ�ɽ����һ�й����߰˸�ľ�Ƶķ䳲��һ��ɽ
ɽ���ϸ�������é�ݡ�\n"NOR);
	set("outdoors", "baihuagu");
	set("exits", ([
		"north"    : __DIR__"baihuagu",
		"westup"   : __DIR__"shanpo1",
		"eastdown" : __DIR__"shanpo2",
		"south"    : __DIR__"baihuagu1",
		"west"     : __DIR__"baihuagu",
		"east"     : __FILE__,
	]));
	set("objects", ([
	]));
	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -360);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
