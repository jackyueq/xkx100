// /d/shenlong/caodi.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ����Ĳݵأ��м�����������ˣ�����ܿ����˸�ɫ����
����һ�����紵�������µĿ����д������Ƶ����Ļ��㡣
LONG );
	set("exits", ([
		"west"  : __DIR__"kongdi",
		"north" : __DIR__"xiaowu",
	]));
	set("outdoors", "shenlong");
	set("no_clean_up", 0);
	set("coor/x", 4000);
	set("coor/y", 3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
