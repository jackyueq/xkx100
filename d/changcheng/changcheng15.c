// Room: /d/changcheng/changcheng15.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
���ڳ����ܵ���ɳ����ʴ��һС�γ�ǽ�Ѿ���������ֻ����ʱ����
�ߵ�С·�ƹ�ȥ������������Կ�������Ȼ�еĵط��Ѿ�������������
������Ȼ��ΰ��������ɽ������������ɽ�������ȥ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"northwest" :__DIR__"changcheng16",
		"east"      :__DIR__"changcheng14",
	]));
	set("no_clean_up", 0);
	set("coor/x", -12000);
	set("coor/y", 9000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}