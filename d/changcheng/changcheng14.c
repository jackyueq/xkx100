// Room: /d/changcheng/changcheng14.c
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
		"west"      :__DIR__"changcheng15",
		"southeast" :__DIR__"fenghuotai2-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -11000);
	set("coor/y", 9000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}