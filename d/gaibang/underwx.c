// Room: /d/gaibang/underwx.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ݶ�����");
	set("long", @LONG
������������������ؤ�����ֶ�ݶѵĶ�����ܶ����˸�����
�����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"   : "/d/wuxi/dayifenduo",
		"south" : __DIR__"wxandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/xie" : 1,
	]));
	set("coor/x", 400);
	set("coor/y", -740);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
