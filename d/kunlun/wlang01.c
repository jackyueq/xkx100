// Room: /d/kunlun/wlang01.c
// Last Modified by Winder on Nov. 15 2000

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
long );
	set("exits",([
		"east" : __DIR__"qianting",
		"west" : __DIR__"wlang02",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}