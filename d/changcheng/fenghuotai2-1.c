// Room: /d/changcheng/fenghuotai2-1.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���̨");
	set("long", WHT @LONG
�����Ƿ��̨���ڲ������ﲻ�Ǻ���������������ķ���һЩ���
����ǽ�ı������ϵı���ȴ���������������ɼ���Ȼ����ܼ�࣬����
ʿ��ȴû�������Լ������Ρ�
LONG
NOR );
	set("exits", ([
		"up"       :__DIR__"fenghuotai2-2",
		"east"     :__DIR__"changcheng13",
		"northwest":__DIR__"changcheng14",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10010);
	set("coor/y", 8000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}