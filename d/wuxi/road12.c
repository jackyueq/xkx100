// Room: /d/wuxi/road12.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "����С��");
	set("long", @LONG
����̫�����ϵ�һ��С�������Ի�������������ݺ�����䡣����
��һ���޼ʵ�̫�����̲����꣬�̲����죬��֮�����泩��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"road11",
		"northeast" : __DIR__"road13",
	]));
	set("coor/x", 380);
	set("coor/y", -880);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}