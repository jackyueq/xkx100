// Room: /d/changcheng/changcheng16.c
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
		"northup"   :__DIR__"changcheng17",
		"southeast" :__DIR__"changcheng15",
	]));
	set("no_clean_up", 0);
	set("coor/x", -13000);
	set("coor/y", 10000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}