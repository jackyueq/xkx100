// Room: /d/xingxiu/chouchishan.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"���ɽ"NOR);
	set("long", @LONG
����������ţ������Ƹߣ�ɽ��εض���ֱ�����졣ɽ��ƽ��ǧĶ����
��������������ģ������ºͣ�Ȫˮ�࣬ʤ����ɽ�����ʯɫ���죬��ˮ����
ǿ����������С�����ܡ�ԶԶ���Կ������ϱ���һ����ΰ�Ĺذ���
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southeast" : __DIR__"silk1",
		"north"     : __DIR__"silk2",
		"southwest" : __DIR__"shuiliandong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20000);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

