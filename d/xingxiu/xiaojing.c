// Room: /d/xingxiu/xiaojing.c
// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���������޺�����Բ�����ﶼ��һ���޼ʵĺ��������󣬵�����
���˳�֮Ϊ��������Ҳ��������ʪ�����深ֳ���������޵��ӳ����˲�
׽���棬�Ա�����֮�á�����ͨ�����޺������������һ��С������
�Ե�׺��Щ���ܡ�����ϡ�٣��������޺���һ����ˡ����ɵ������Ļ�
ŭ�ţ�������С����
LONG
	);
	set("exits", ([
		"east" : __DIR__"xxh2",
		"west" : __DIR__"shidao",
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50100);
	set("coor/y", 20200);
	set("coor/z", 0);
	set("yushi_count", 1);
	setup();
}

void init()
{
	object obj, me = this_player();
	mapping fam;
	fam = (mapping)me->query("family");
  
	if(mapp(fam) && fam["family_name"] == "������" &&
		me->query("xx_points") > 10 &&
		(random(30) == me->query("kar")) &&
		query("yushi_count") >= 1 &&
		!me->query_temp("yushi_get"))
	{
		write("�㿴�������и�����һ"WHT"��"NOR"���������ŷ���ԭ����һС����ʯ��\n");
		me->set_temp("yushi_get", 1);
		obj = new(__DIR__"obj/yushi");
		obj->move(me);
		add("yushi_count", -1);
	}
}

