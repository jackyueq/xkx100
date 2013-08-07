// Room: /d/suzhou/tianpingshan.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "��ƽɽ");
	set("long",@long
��������ɽ�����뼸��ؾ͵�����ƽɽ����Ϊ����������ɽ֮���
�塣��ɽ�����ƽ̹���ƶ�����������ɽ�Ƹ߾����������ƣ�Ҳ�ơ���
��ɽ�������أ���������������ƽɽ���뷶����������Ҳ�ơ�����ɽ����
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"qsgdao",
		"north" : __DIR__"shihu",
		"southeast" : __DIR__"lingyanshan",
		"eastup" : __DIR__"baiyunquan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
