// tianshan: /d/xingxiu/shanjiao.c
// Last Modified by winder on Feb. 28 2001
inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
��������ɽ���£������Ǹ������Ƶ���ɽ�������ʱ����Կ���ɽ
���ϵı�����һ����ɽ�������Ϊ���롣�������������ľ۾�������
�����ޱߵ���������ɴ�ɳĮ��������ͨ����ɽ��·�ؽ����ԭ�ĸ��
ɳĮ��
LONG );
	set("exits", ([
		"westup"    : __DIR__"tianroad1",
//		"east"      : "/d/gaochang/road",
		"east"      : "/d/hasake/senlin1",

		"southwest" : "/d/huijiang/gebi1",
		"northeast" : __DIR__"yilihe",
		"southeast" : __DIR__"silk5",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xiyu" );
	set("objects", ([
		__DIR__"npc/trader" : 1,
		__DIR__"npc/hkid" : 1,
		__DIR__"npc/xxdizi1" : 1,
	]));
	set("coor/x", -40000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int current_water;
	object ob;
	if (dir == "southwest")
	{
		if (!userp(me)) return 0;
		current_water = me->query("water");
		if (current_water==0)
		{
		}

		if (current_water>0 && current_water<20)
		{
			me->set("water",0);
		}
		if (current_water>20)
		{
			me->set("water",current_water-20);
		}
		return ::valid_leave(me, dir);
	}
	if(me->query_temp("wait_target") &&
		objectp(present("anran zi", environment(me))))
		return notify_fail("��Ȼ��������������ǰ���ȵ�������������ҹ�������\n");
	if(me->query_temp("xx_rob") &&
		objectp(ob = present("hubiao biaoshi", environment(me))) &&
		ob->query("target") == me)
		return notify_fail("������ʦ������ס���ȥ·�����������������ˣ�\n");  
	if(me->query_temp("xx_rob") && objectp(present("shangdui",environment(me))))
		return notify_fail("�̶��������أ�����(qiang)����\n");  
	return ::valid_leave(me, dir);
} 
