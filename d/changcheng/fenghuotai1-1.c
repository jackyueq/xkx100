// Room: /d/changcheng/fenghuotai1-1.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���̨");
        set("long", WHT@LONG
�����Ƿ��̨���ڲ������ﲻ�Ǻ���������������ķ���һЩ���
����ǽ�ı������ϵı���ȴ���������������ɼ���Ȼ����ܼ�࣬����
ʿ��ȴû�������Լ������Ρ�
LONG
NOR );
        set("exits", ([
                "up"        :__DIR__"fenghuotai1-2",
                "southdown" :__DIR__"changcheng7",
                "westdown"  :__DIR__"changcheng8",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -6000);
	set("coor/y", 7000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}