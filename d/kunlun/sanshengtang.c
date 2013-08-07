// Room: /d/kunlun/sanshengtang.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʥ��");
	set("long", @long
������ʥ���ˡ�������ʥ�������������ԭΪ���������ԣ�������
������������������׳������Զ�����������������ɾ������£���
����·����Ӣ�۵ĵط�����������ʥ��Ҳֻ�����ٰ��������ˡ�
long);
	set("exits",([
		"west"      : __DIR__"jiuqulang7",
		"east"      : __DIR__"jiuqulang3",
		"north"     : __DIR__"jiuqulang5",
		"south"     : __DIR__"jiuqulang1",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/banshuxian" :   1,
		__DIR__"npc/kl-dizi1.c" :   1,
		__DIR__"npc/kl-dizi4.c" :   1,
	]));
	set("coor/x", -119990);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");
	if (dir == "north" &&
		objectp(present("ban shuxian", environment(me)) &&
		(!fam || fam["family_name"] != "������")) &&
		!me->query_temp("kl_pass"))
	{
		return notify_fail("�������ס�㣬˵�����������ܹ���������һ�أ������������ټѴ���\n");
	}
	if (dir == "south" && me->query("kl_pass"))
		me->delete_temp("kl_pass");
	return ::valid_leave(me, dir);
}
