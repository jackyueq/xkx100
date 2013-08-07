// Room: /d/jiaxing/xiaodian.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_move(string);
int do_turn(string);

void create()
{
	set("short", "С�Ƶ�");
	set("long", @LONG
����һ���Ѿ������˵�С�Ƶ꣬��̨�ϻ����˻ң�һ�����������
һ��Ѹɲݣ��Ա�б����һ�������棻��̨��ĳ��������ҵط��ż���
�ƾɵ��໨����(wan)������ǰ����һ�����ų�����С���
LONG
	);

	set("item_desc", ([
		"wan"      : "һ�Ѻ����ҵ�ɢ���ŵ��롣\n",
		"bowl"     : "һ�Ѻ����ҵ�ɢ���ŵ��롣\n",
		"tiewan"   : "һֻ��ֵ��룬�����ǹ̶����˼����ϡ�\n",
		"ironbowl" : "һֻ��ֵ��룬�����ǹ̶����˼����ϡ�\n",
	]) );

	set("exits", ([
		"north" : __DIR__"njroad1",
	]));

	set("objects", ([
		__DIR__"npc/shagu": 1,
	]));

	set("coor/x", 1560);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_move","yi");
	add_action("do_turn","turn");
	add_action("do_turn","zhuan");
}

int do_move(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (arg == "wan" || arg == "bowl")
	{
		write( "�㽫�����ϵ���ʹ����ˤ������ȥ��ȴ������һֻ�뾹Ȼ�ò���������ϸһ�����ŷ�������һֻ����(tiewan)��\n");
		me->set_temp("mishi_temp",1);
		return 1;
	}
	return notify_fail("��Ҫ�ᶯʲô��\n");
}

int do_turn(string arg)
{
	int temp;
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (arg == "tiewan left" || arg == "tiewan zuo")
	{
		temp = me->query_temp("mishi_temp");
		if (!temp) return 0;
		if (temp < 4) temp++;
		else temp = 1;
		write("�㽫�����þ�������⶯�������ˡ���֨����������\n");
		me->set_temp("mishi_temp",temp);
		return 1;
	}
	if (arg == "tiewan right" || arg == "tiewan you")
	{
		temp = me->query_temp("mishi_temp");
		if (!temp) return 0;
		if (temp > 3) temp++;
		else temp = 1;
		write("�㽫�����þ������Ұ⶯�������ˡ���֨����������\n");
		if (temp == 7)
		{
			write( "ֻ����������һ�����죬�����ǰ������һ���š��������ԥ�����˽�ȥ��\n");
			message("vision","���ܺ����Ȼ�ֳ�һ�����ţ�" + me->name() + "�ٲ����˽�ȥ������֨ѽѽ���ֹ����ˡ�\n", this_object(), me);
			me->delete_temp("mishi_temp");
			me->move(__DIR__"mishi");
			message("vision", me->name() + "�򿪰��ţ����˽�����\n", environment(me), me);
		}
		else me->set_temp("mishi_temp",temp);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}