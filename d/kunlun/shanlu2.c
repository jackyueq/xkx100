// Room: /d/kunlun/shanlu2.c
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
		"eastdown" : __DIR__"shanlu1",
		"northup"  : __DIR__"bayankala",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -90000);
	set("coor/y", 5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}