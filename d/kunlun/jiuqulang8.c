// Room: /d/kunlun/jiuqulang8.c
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
		"north" : __DIR__"jiuqulang7",
		"east" : __DIR__"jiuqulang1",
		"southwest" : __DIR__"nanwoshi",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40090);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest" && me->query("gender") != "����")
		return notify_fail("�����ͷ���˽�ȥ��ȴ���������������ң����ɵ����Ϸ��գ�һŤͷ���˳�����\n");
	return ::valid_leave(me, dir);
}