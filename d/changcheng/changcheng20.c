// Room: /d/changcheng/changcheng20.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
���ڳ����ܵ���ɳ����ʴ�����ٳ�ǽ�Ѿ�������ǽ�ǵĻ�ɳ������
��ӳ�ǽ�ϵ���������ש��̧����ȥ��ֻ����ǽ����һ���ޱߵĻ�ɳ��
��Χ�������ˣ���һƬ���������磬ż�����Ϸɹ�һֻ��ӥ��ԶԶ�Ŀ�
�Կ���������һ���ؿ���
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"      :__DIR__"changcheng21",
		"northeast" :__DIR__"changcheng19",
	]));
	set("no_clean_up", 0);
	set("coor/x", -16000);
	set("coor/y", 9000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}