// Room: /d/kunlun/huayuan1.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long",@long
�����������ɵĻ�԰���ȱ߻�ľ���裬��Ӱ�βɽȪ���ģ���Ȼ
���н���԰�ֵ���Ȥ�������Ǿ����ҡ�
long);
	set("exits",([
		"north" : __DIR__"jiuqulang1",
		"south" : __DIR__"shilu1",
		"west"  : __DIR__"jingxiushi",
		"east"  : __DIR__"lianwu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}