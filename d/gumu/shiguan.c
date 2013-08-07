// Room: /d/gumu/shiguan.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"ʯ����"NOR);
	set("long", @LONG
�׸��ڲ��ƺ�д�����֣���Ŀ��ȥ��������ʮ�������֣�����Ů��
������ѹȫ�档����һ�����������ˡ�����ʮ��������Ũī���飬����
�Ծ�������������ʱ�׸�ֻ�ƿ���һ�룬��б�ۿ�ȥ���������������
LONG	);
	set("exits", ([ 
		"out" : __DIR__"lingshi",
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("coor/x", -3000);
	set("coor/y", -40);
	set("coor/z", 70);
	setup();
}

void init()
{
	add_action("do_dian", "use");
	add_action("do_dian", "dian");
	add_action("do_turn", "turn");
	add_action("do_turn", "zhuan");
	add_action("do_ti", "ti");
	add_action("do_search","search");
}

int do_dian(string arg)
{
	object ob,me=this_player();

	if ( arg == "fire")
	{
		if(!objectp(ob = present("fire", me)))
			return notify_fail("��û�л��ۣ���ʲô��\n");
		message_vision(HIR"ֻ�������� ---����һ����$N���������еĻ��ۡ�\n\n"NOR,me);
		write(HIY"�ٿ���ʮ������ʱ��ֻ�����д�������С�֣��ƽ���Ů�ľ�֮��������֮�ڴ���֮�£�������Ե��һ�۱�֪ ......�������� .....\n"NOR);
		me->set_temp("marks/��Ĺ1", 1);
		return 1;
	}
	return 0;
}

int do_search()
{
	object me = this_player();

	if (!me->query_temp("marks/��Ĺ1")) return 0;
	if (me->query_temp("gumu1") < 8)
	{
		message_vision(HIY"$N�������ۣ���ϸ����ʯ��������������\n"NOR,me);
		me->add_temp("gumu1",1);
		return 1;
	}
	message_vision(HIR"$N��������һ������Ȼ����������һ�ֵİ�(ao)����\n"NOR,me);
	me->delete_temp("marks/��Ĺ1");
	me->delete_temp("gumu1");
	me->set_temp("marks/��Ĺ2", 1);
	return 1;
}

int do_turn(string arg)
{
	object me=this_player();
	string dir;
	if (!me->query_temp("marks/��Ĺ2")) return 0;
	if (!arg||arg=="") return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if( arg=="ao" )
	{
		write("��Ҫ�Ѱ���������ת��\n");
	}
	if( sscanf(arg, "ao %s", dir)==1 )
	{
		if( dir=="left")
		{
			message_vision(HIG"$N����������ת�����£���Ȼ��Щ�ɶ���\n"NOR, me);
			me->delete_temp("marks/��Ĺ2");
			me->set_temp("marks/��Ĺ3", 1);
		}
		else
			return notify_fail("�㽫��������ת�˼��£����ʲôҲû������\n");
	}
	return 1;
}

int do_ti(string arg)
{
	object me =this_player();

	if (!me->query_temp("marks/��Ĺ3")) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg =="up")
	{
		message_vision(YEL "$N������ס�˰�������һ�ᣬֻ������һ�죬�׵�ʯ��Ӧ�ֶ���$N⧲���������������²�ʯ�ҡ�\n"NOR,me);
		me->delete_temp("marks/��Ĺ3");
		me->move(__DIR__"shishi6");
		return 1;
	}
	return notify_fail("���������᣿\n");
}
