// Room: /d/nanshaolin/ting.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"ӭ��ͤ"NOR);
	set("long", @LONG
������ӳ֮�У�һ��ʯͤ��Ȼ���С�ֻ��ͤ���Ҷ������ɷ������
�š�ӭ��ͤ���������֡���������ʿ���ڴ���������������ı�������
�ɽ������ڡ�ͤ��������֪��ɮ����æµ���д���������͡�
LONG );
	set("exits", ([
		"westdown" : __DIR__"fxjing",
		"northup"  : __DIR__"shanlu2",
		"east"     : __DIR__"shanlu1",
	]));
	set("outdoors", "nanshaolin");
	set("no_fight", 1);
	set("objects",([
		CLASS_D("nanshaolin") + "/fangtong" : 1,
		CLASS_D("nanshaolin") + "/fangkong" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
}

int do_quit()
{
	object ob = this_player();
	if (ob->query_condition("sl_lunzhi")>0)
	{
		write("��������ֵ�������˳���Ϸ��\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv;
	mapping myfam, mygen;
	int i;

	myfam = (mapping)me->query("family");
	if (!me->query("luohan_winner") && !present("yingxiong ling", me))
	if (me->query("gender") == "Ů��" && dir == "northup" )
	{
		if(objectp(present("fang tong", environment(me))))
			return notify_fail("��ͨ������ס�����һ��˵����ǧ����������������Ů�����롣"+RANK_D->query_respect(me) +"\n����ɽȥ�ɣ��������ûȤ��\n");
		if(objectp(present("fang kong", environment(me))))
			return notify_fail("����������������ǰ��˫�ֺ�ʲ˵���������ӷ���λ" + RANK_D->query_respect(me) +"��������\nˡС�²��Ӵ�Ů�͡�Ůʩ������һ����𣬺η�ȥ��üɽ��ϲ��\n");
	}
	if((!myfam ||
		myfam["family_name"] != "������" &&
		myfam["family_name"] != "��������" ) &&
		dir == "northup")
	{
		inv = all_inventory(me);
		for(i=sizeof(inv)-1; i>=0; i--)
			if(inv[i]->query("weapon_prop") &&
				(inv[i]->query("equipped")))
			{
				if(objectp(present("fang tong",environment(me))))
					return notify_fail("��ͨ��ס��˵������λ"+RANK_D->query_respect(me) +"����±��С�����ǧ��Ĺ�أ����\n���óֱ�����ɽ��\n");
				if(objectp(present("fang kong", environment(me))))
					return notify_fail("����������������ǰ��˫�ֺ�ʲ˵���������ӷ���λ"+RANK_D->query_respect(me) +"������\n���С������徲֮�أ����������赶Ū��������ʩ�����¡�\n");
			}
	}
	if (!me->query("muren_winner") && mapp(myfam) &&
		myfam["family_name"]== "��������" && 
		dir == "east" ) 
	{
		if(objectp(present("fang tong", environment(me))))
			return notify_fail("��ͨ������ס�㹪��˵������λʦ���书��δ���ã�������ɽ������������������ֵ�������\n");
		if(objectp(present("fang kong", environment(me))))
			return notify_fail("����������ס�㹪��˵������λʦ���书��δ���ã�������ɽ����������������ֵ�������\n");
	}

	if (me->query_condition("sl_lunzhi")>0)
		return notify_fail("��������ֵ�������뿪��\n");

	return ::valid_leave(me, dir);
}

