// Room: /d/kunlun/jiuqulang6.c
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
		"northwest" : __DIR__"yaofang",
		"east"      : __DIR__"jiuqulang5",
		"south"     : __DIR__"jiuqulang7",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40110);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}