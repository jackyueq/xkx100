// Room: /d/changcheng/changcheng10.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT@LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�Ͽ��Կ������ٰ����Ĺ�ľ�ԣ������ٵ���Ҳ�������ˣ��ܶ�
�ط��Ѿ�¶����һƬƬ�Ļ�������Ŀ��ȥ������µĳ���˳��ɽ����һ
�����������ѵ����������������ȥ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"    :__DIR__"changcheng11",
		"southup" :__DIR__"changcheng9",
	]));
	set("no_clean_up", 0);
	set("coor/x", -7000);
	set("coor/y", 9000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}