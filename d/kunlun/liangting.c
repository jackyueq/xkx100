// Room: /d/kunlun/liangting.c
// Last Modified by winder on Nov. 15 2000

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	 set("short", "��ͤ");
	 set("long", @LONG
���Ǻ��е�һ��Сͤ�ӣ�������ȥ�����Կ�����������ľ�ɫ����
���Ŀ��������������紵������һƬ���ϴ�ɫ���������������������
����
LONG );
	 set("exits",([
		"east"      : __DIR__"houting",
		"west"      : __DIR__"qinshi",
		"southeast" : __DIR__"jiuqulang5",
		"northeast" : __DIR__"huayuan",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();   
	replace_program(ROOM);
}