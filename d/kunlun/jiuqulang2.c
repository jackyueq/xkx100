// Room: /d/kunlun/jiuqulang2.c
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
		"north"     : __DIR__"jiuqulang3",
		"west"      : __DIR__"jiuqulang1",
		"southeast" : __DIR__"nvwoshi",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40090);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southeast" && me->query("gender") != "Ů��")
		return notify_fail("����Ҫ���ﴳ��ȴ�������������Ѿ�������ľ����ֻ���㬵����˳�����\n");
	return ::valid_leave(me, dir);
}