// Room: /d/kunlun/kuhanlou.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ຮ¥");
	set("long",@long
�����������ɵĿຮ¥��ȡ���ԡ�÷�����Կຮ����֮�⣬������
����ǰ��Ϊ�˼�����������ɵ��Ӷ����ģ������ص��Ӿ���֮����
long);
	set("exits",([
		"north" : __DIR__"shanlin"+(random(5)+1),
		"enter" : __DIR__"kuhanlou1",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119900);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}