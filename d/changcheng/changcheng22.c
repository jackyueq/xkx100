// Room: /d/changcheng/changcheng22.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT@LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�ϵ������ǰ����Ĺ�ľ�ԣ���Ŀ��ȥ������µĳ���˳��ɽ��
��һ�����������ѵ��򶫱������������ȥ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"westup"    :__DIR__"nansilou",
		"northeast" :__DIR__"changcheng23",
	]));
	set("no_clean_up", 0);
	set("coor/x", 3000);
	set("coor/y", 5000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}