// Room: /d/kunlun/shanlu.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long",@long
���н���������һ������һ�죬����������������ǿ����;������
ʲôǿ����ֻ�ǻ�ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ���
long);
	set("exits",([
		"west" : __DIR__"shanlu1",
		"east" : __DIR__"zhenyuanqiao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -70000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}