// Room: /d/kunlun/jiuqulang3.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@long
������ǰ���оŽ����������۵�������ˮ�档һ·������������
ʯ��Ȫ���仨������ˮɫ���ܡ����ߴ����������ӣ�������������ʯΪ
������¥��գ�ת�۴�����Сͤ��ӡ�
long);
	set("exits",([
		"east"      : __DIR__"shufang",
		"west"      : __DIR__"sanshengtang",
		"north"     : __DIR__"jiuqulang4",
		"south"     : __DIR__"jiuqulang2",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}