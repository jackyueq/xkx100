// Room: /d/kunlun/shilu1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long",@long
����һ���̵�ʮ��ƽ����ʯ��·��·���ɨ�ĸɸɾ����������ȥ
�Ǹ���԰�����������㡣
long);
	set("exits",([
		"south" : __DIR__"qianting",
		"north" : __DIR__"huayuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40070);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}