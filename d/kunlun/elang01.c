// Room: /d/kunlun/elang01.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@long
����һ�����ȣ�����ǰ���Ϳͷ������Ͽ������ִ��Ľ�����ʿ��
�����������⣬��һƬ��ɫ�����֣��ľ����£�ֻ�������ϴ���������
����
long);
	set("exits",([
		"west" : __DIR__"qianting",
		"east" : __DIR__"elang02",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}