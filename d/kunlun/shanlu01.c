// Room: /d/kunlun/shanlu01.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long",@long
�����Ѿ��������ɵĵط��ˣ�·�߻������أ���Ȼ�Ǻ���������ȴ
��Ȼ���������������������޵Ľ�����ǰ��ɽ�Ͼ��������ɵľ����ˣ�
����������ʱ���ɽ�š�
long);
	set("exits",([
		"westdown" : __DIR__"shanmen",
		"northup"  : __DIR__"shanlu02",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}