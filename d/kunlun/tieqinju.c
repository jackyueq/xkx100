// Room: /d/kunlun/tieqinju.c ���پ�
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","���پ�");
        set("long",@long
������ǡ�������������̫��ľӴ������������Ϊ���ɣ���Ʒ��
�����������ǲ�ͬ�����������ɵ��������������������ɫ������ͨ
�����ҡ�
long );
	set("objects",([
		CLASS_D("kunlun")+"/hetaichong" : 1,
		__DIR__"npc/kl-dizi2.c" :   1,
		__DIR__"npc/kl-dizi4.c" :   1,
	]));
	set("exits", ([
		"south" : __DIR__"huapu",
		"east"  : __DIR__"sleeproom",
	]));
	create_door("east", "С��", "west", DOOR_CLOSED);
	set("coor/x", -119980);
	set("coor/y", 40140);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if (dir == "east" &&
		objectp(present("he taichong", environment(me))) &&
		(!fam || fam["family_name"] != "������") &&
		!me->query_temp("kl_pass"))
		return notify_fail("��̫����ס�㣬˵�������Ϊ�ھ��ס�������������Ϊ�ǡ�\n");

	return ::valid_leave(me, dir);
}