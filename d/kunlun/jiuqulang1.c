// Room: /d/kunlun/jiuqulang1.c
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
		"west"  : __DIR__"jiuqulang8",
		"east"  : __DIR__"jiuqulang2",
		"north" : __DIR__"sanshengtang",
		"south" : __DIR__"huayuan1",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119990);
	set("coor/y", 40090);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}