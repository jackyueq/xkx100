// Room: /d/changcheng/changcheng1.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT@LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�ϵ������ǰ����Ĺ�ľ�ԣ���Ŀ��ȥ������µĳ���˳��ɽ��
��һ�����������ѵ��򶫡��������ȥ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west" :__DIR__"changcheng2",
		"east" :__DIR__"juyongguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}