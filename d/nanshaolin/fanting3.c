// Room: /d/nanshaolin/fanting3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

string* names = ({
	FOOD_DIR+"mizhi-tianou",
	FOOD_DIR+"jiaxin-biji",
	FOOD_DIR+"basi-shanyao",
	FOOD_DIR+"furong-huagu",
});

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ȫ����ɮ��ի�ĵط��������������������ǧ��ͬ
ʱ���š��Ӷ�����һ���Ű����˳����Ĳ����ͳ��ʣ���λС����������
æµ�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ��
�����ӵ�һ����һ���С��ͭ��(luo)�������Ǹ�������
LONG
	);
	set("exits", ([
		"north" : __DIR__"fanting1",
		"east"  : __DIR__"chufang2",
	]));
	set("item_desc", ([
		"luo" : "����һ��ͭ�Ƶ�С�࣬��ɮ�����ٻ���ի��Сɳ���õġ�\n",
	]));
	set("objects",([
		__DIR__"npc/xiao-nan3" : 1
	]));
	set("coor/x", 1850);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_tap", "qiao");
	add_action("do_tap", "knock");
	add_action("do_zuo", "zuo");
	add_action("do_zuo", "sit");
}

int do_tap(string arg)
{
	object me = this_player();
	object cui;
	if (!arg || (arg != "luo"))
	{
		return notify_fail("��Ҫ��ʲô��\n");	
	}
	if( !objectp(cui = present("xiao shami", environment(me))) )
	 	return notify_fail("������һ��С�࣬ȴ����û�����㡣\n");
	if( !me->query_temp("marks/sit") )
		return notify_fail("������һ��С�࣬�����ڷ����ڻص�����ͻȻ�о��Լ����޴���\n");
	if( me->query_temp("marks/served") )
	{
		message_vision("Сɳ�ֶ�$N˵��������������������ᣬ��Ҳ��������������ѽ������\n", me);
		return notify_fail("");
	}
	message_vision("$N��������ǰ����������һ�����ϵ�С�࣬Сɳ�ֹ������˸�Ҿ�������к���\n", me);
	cui->serve_food(me) ;
	me->set_temp("marks/served", 1);
	remove_call_out("delete_served");
	call_out("delete_served", 10, me);

	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_zuo(string arg)
{
	if ( !arg || (arg != "changdeng" && arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");	
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���¡�\n");	
}

int valid_leave(object me, string dir)
{
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}

