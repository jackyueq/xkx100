// Room: /d/kunlun/shanlu1.c
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
		"westup" : __DIR__"shanlu2",
		"east"   : __DIR__"shanlu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -80000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}