// Room: /d/changcheng/changcheng12.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�ϵĹ�ľ���Ѿ����󶫱ߵ���ô���ˣ���Ҳ�����˲��٣��ܶ�
�ط��Ѿ�¶����һƬƬ�Ļ�������Ŀ��ȥ������µĳ���˳��ɽ����һ
�����������ѵ��򶫣����������ȥ��������ȥ������ϡ�٣�����е�
һƬ������
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"south" :__DIR__"changcheng13",
		"east"  :__DIR__"changcheng11",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10000);
	set("coor/y", 9000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}