// Room: /d/wuxi/road13.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "����С��");
	set("long", @LONG
����̫�����ϵ�һ��С�������ѱ�ȥ��һ·ǰ�У����ݽ����
����һ���޼ʵ�̫�����̲����꣬�̲����죬��֮�����泩��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"   : __DIR__"road12",
	]));
	set("coor/x", 390);
	set("coor/y", -870);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}