// Room: /d/guiyun/road3.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int go_north();
int go_south();
int do_go(string arg);

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ��������С·�������濴Զ���ƺ���һ��С�ƹݡ������濴Զ��
�ƺ���һ��ׯ԰��
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guiyun");

	set("exits", ([
		"south": __DIR__"road2",
		"north": __DIR__"road4",
	]) );

	setup();
}

void init()
{
	object me=this_player();

	if (!me->query_temp("guiyun_road"))
		me->set_temp("guiyun_road", random(4)+2);
	add_action("go_north","north");
	add_action("go_south","south");
	add_action("do_go","go");
}

int go_north()
{
	object me=this_player();
	int road;
	
	road = me->query_temp("guiyun_road");
	if (road > 1) {
		road--;
		me->set_temp("guiyun_road", road);
		me->move(__FILE__);
	}
	else {
		me->move(__DIR__"road4");
		me->delete_temp("guiyun_road");
	}
	return 1;
}

int go_south()
{
	object me=this_player();
	int road;
	
	road = me->query_temp("guiyun_road");
	if (road > 1)
	{
		road--;
		me->set_temp("guiyun_road", road);
		me->move(__FILE__);
	}
	else {
		me->move(__DIR__"road2");
		me->delete_temp("guiyun_road");
	}
	return 1;
}

int do_go(string arg)
{
	object me=this_player();
	int road;
	
	if (arg != "north" && arg !="south") return 0;
	road = me->query_temp("guiyun_road");
	if (road > 1)
	{
		road--;
		me->set_temp("guiyun_road", road);
		me->move(__FILE__);
	}
	else {
		if (arg == "north")
			me->move(__DIR__"road4");
		else
			me->move(__DIR__"road2");
		me->delete_temp("guiyun_road");
	}
	return 1;
}
