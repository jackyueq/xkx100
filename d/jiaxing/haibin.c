// Room: /d/jiaxing/haibin.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_jump(string arg);
int do_look(string arg);
int do_use(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǯ�������뺣�ڡ�������ӿ��������Ϣ������(tide)���ϵ�
������������ڰ��ߣ������ˮ���ڰ�շ��裬�����ѩ�׷�һ����
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"west": __DIR__"jiangpan3.c",
	]) );

	set("item_desc", ([
		"tide" : "���������������ƺ����������û��\n",
	]) );

	set("coor/x", 1610);
	set("coor/y", -1090);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
	add_action("do_use", "use");
	add_action("do_look", "look");
}
/*
void relay_revive(object me)
{
	add_action("do_jump", ({"jump", "tiao"}));
	add_action("do_use", "use");
	add_action("do_look", "look");
}
*/
int do_use(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat"))
	{
		me->delete_temp("thd_boat");
		write("������С�������������һ�����\n");
		write("��������˳�磬������ƣ������ڱ㵽���ˡ�\n");
		me->move("/d/taohua/shore");
		return 1;
	}
	return 0;
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (arg == "boat" || arg == "chuan")
		return do_use(arg);

	if (arg != "chao" && arg != "tide")
		return notify_fail("��Ҫ����������\n");

	if (me->query_dex() < 59)
		return notify_fail("����ͼ���������ȴ�ܾ����������ġ�\n");

	if (me->query_skill("dodge") < 80)
		return notify_fail("����ͼ���������ȴ�����Լ����Ṧ��Ϊ��û�дﵽ��ô�ߵľ��硣\n");
	message_vision("$N����һԾ�������˺����У�\n", me);
	me->move("/d/taohua/tide");
	return 1;
}

int do_look(string arg)
{
	object me = this_player();

	if (me->query("family/master_name") != "��ҩʦ" || me->query_skill("count", 1) < 50)
	{
		set("long", @LONG
������Ǯ�������뺣�ڡ�������ӿ��������Ϣ������(tide)���ϵ�
������������ڰ��ߣ������ˮ���ڰ�շ��裬�����ѩ�׷�һ����
LONG
);
		me->look(arg);
	}
	else
	{
		if (!arg)
		{
			set("long", @LONG
������Ǯ�������뺣�ڡ�������ӿ��������Ϣ������(tide)���ϵ�
������������ڰ��ߣ������ˮ���ڰ�շ��裬�����ѩ�׷�һ����Զ
����һ�����(rock)�������ƺ�������ʲô��
LONG
);
			me->look(arg);
		}
		else if (arg == "rock" || arg == "yanshi" || arg == "juyan")
		{
			write("һ����ң�������Լ¶��һ����(boat)�Ĵ�������\n");
			me->set_temp("thd_boat", 1);
			return 1;
		}
		else if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat"))
		{
			write("һ�����ŵ�С��������ͨ���������Ǻ��ѷ��ֵġ�\n");
			return 1;
		}
	}
}