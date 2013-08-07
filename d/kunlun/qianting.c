// Room: /d/kunlun/qianting.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long",@long
�����������������ܴ��ߣ�ʮ�ֵļ��Ӷ�׳�������ڰڼ��Ÿ߱���
�Σ�һ�Ű������������ǽӴ����˵ĵط�������Ͷ���Ҳ�ǿ���������
��ЪϢ������һ������ͨ����档
long);
	set("exits",([
		"south" : __DIR__"pingfeng",
		"north" : __DIR__"shilu1",
		"west"  : __DIR__"wlang01",
		"east"  : __DIR__"elang01",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/xihuazi" : 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", -119990);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	"/clone/board/kunlun_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if ((!fam || fam["family_name"] != "������") && dir == "north" &&
		objectp(present("xi huazi", environment(me))))
		return notify_fail("��������ס�㣬˵���������������ɵĵ��̣���Ҫ�����Ҵ���\n");

	return ::valid_leave(me, dir);
}