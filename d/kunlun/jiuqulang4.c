// Room: /d/kunlun/jiuqulang4.c
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
		"northeast" : __DIR__"liangong",
		"south"     : __DIR__"jiuqulang3",
		"west"      : __DIR__"jiuqulang5",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40110);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}