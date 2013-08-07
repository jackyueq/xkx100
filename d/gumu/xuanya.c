// Room: /d/gumu/xuanya.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIM"����"NOR);
	set("long", @LONG
�˴���������ɽ��·����ͺͺ��ʯ�ڣ�������������������������
��(xuanya)���������и���Ĺ�������ܲ��˹�Ĺ֮���������Ӵ˴�һ
Ծ���£���ȴһ���������±��п�Ħ�����(tree)��֦Ҷ��ʢ�����ɡ
һ������ס��Բ֮�ء�
LONG	);
	set("outdoors","gumu");
	set("exits", ([
		"west" : __DIR__"mumen",
	]));
	set("item_desc", ([
		"xuanya" : "������һƬ�������ơ���(tiao)��ȥ������ȥ�޻ء�\n",
		"tree"   : "һ�øߴ�ľ���������������������ҡ�εĺۼ���\n", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", 40);
	set("coor/z", 90);
	setup();
}

void init()
{
	object room, me = this_player();

	if (random(me->query("kar")) >= 15 )
	{
		if(!( room = find_object(__DIR__"tree")))
			room = load_object(__DIR__"tree");
		if(!(present("du mang", room))) return;
		message_vision(HIR "ͻȻ�ŵ�һ���ȳ�֮���������ϵ�����һ����ڴ�ϸ������ͷ��������$N�����ˡ�\n\n"NOR, me);
		me->move(__DIR__"tree");
		me->start_busy(3);
	}
	else
	{
		add_action("do_tiao", "tiao"); 
		add_action("do_yao", "yao");
		add_action("do_climb", "climb");
		add_action("do_climb", "pa");
	}
}

int do_tiao(string arg)
{ 
	object me = this_player();

	if ( arg == "xuanya")
	{
		if (me->query_temp("mark/jump") < 2)
		{
			write("������̣��ҹ�Ĺ�񹦾��������ٿ���һ�°ɡ�\n");
			me->add_temp("mark/jump", 1);
			return 1;
		}
		message_vision(HIR "$N�����������£�����һ�����ֵܽ����ǣ������ټ������������ڶ���\n"NOR, me);
		me->delete_temp("mark/jump");
		me->set_temp("last_damage_from", "������ɱ��");
		me->unconcious();
		me->die();
		return 1;
	}
	return notify_fail("��Ҫ�������\n");
}

int do_yao(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("parry", 1);
	c_exp=me->query("combat_exp");

	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("ҡʲôҡ��û����������\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (me->query("qi") < 30)
		return notify_fail("���۵ù�Ǻ��ȥ����ЪϢ�ɡ�\n");
	if (arg == "tree")
	{
		if (c_skill < 50)
			return notify_fail("��ʹ������ľ��������Ǵ���ȴ��˿������\n");
		if (c_skill > 100)
			return notify_fail("��ʹ����ҡ�δ��������ִ����챻��ҡ���ˡ�\n");
		write("��ʹ����ҡ���Ŵ�������Ĵ���΢΢�ζ���\n");
		me->receive_damage("qi", 10 + random(20));
		if (c_skill*c_skill*c_skill/10 < c_exp )
			me->improve_skill("parry", random(me->query("int")));
		return 1;
	}
	return notify_fail("��Ҫҡʲô��\n");
}

int do_climb(string arg)
{ 
	object me = this_player(); 

	if (arg == "tree")
	{
		message_vision(YEL"$N��������������ȥ��\n"NOR, me);
		if (me->query_skill("dodge", 1) < 30)
		{
			message_vision(HIR"���$N������һ�����������\n"NOR, me);
			me->receive_wound("qi", random(5) + 5);
			return 1;
		}
		message_vision(HIY"$N�ܿ���ʧ��Ũ����Ҷ�С�\n"NOR, me);
		me->move(__DIR__"tree");
		return 1;
	}
	write("������������\n");
}

