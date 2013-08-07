// Room: /d/gumu/woshi1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short",HIC"С����"NOR);
	set("long", @LONG
�����������������ң����пտն�����һ�鳤����ʯ����������
�����Ų�ϯ��һ���ײ������������������һ���˸ߵ�����������У�
�������
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao20",
	]));
	set("objects", ([
		__DIR__"obj/bed" : 1,
	]));
	set("sleep_room", 1);
	set("no_fight", 1);

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_zuo", "zuo");
	add_action("do_zuo", "sleep");
	add_action("do_liao", "liao");
}

int do_zuo(string arg)
{
	object me = this_player();
	int exp, lvl;

	exp = me->query("combat_exp");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (arg == "bed" || arg == "chuang")
	{
		if( me->query_skill("yunv-xinfa", 1) < 1)
		{
			message_vision("$N���ڵ��ڹ����ܲ�ס���񴲵ĺ���֮����\n", me);
			me->start_busy(1);
			return 1;
		}
		if(me->query("neili") < 300 )
		{
			message_vision("$N���ڵĹ������ܲ�ס���񴲵ĺ���֮����\n", me);
			me->start_busy(1);
			return 1;
		}
		lvl = (int)me->query_skill("force", 1);
		if(lvl > 100 && lvl < 200)
		{
			message_vision("$N�����˺��񴲣���ʼǱ���ڹ���ʹ��Ϣ���д�С���졣\n", me);
			if (random(10) > 6)
			{
				message_vision("$N��Ϣ��ϣ�ֻ���þ���������Ϣ���������ڶ�����\n", me);
				if ((lvl*lvl*lvl/10) < exp)
				{
					me->improve_skill("force", random(lvl));
				}
				me->receive_damage("qi", random(lvl/3));
			}
			else
				message_vision("$N��Ϣ��ϣ�վ������������������������ûʲô������\n", me);
		}
		else
			message_vision("$N���Ϻ��񴲣�ֻ���ñ���̹ǣ���������һ���Ǳ�����������������\n", me);
		me->start_busy(1);
		return 1;
	}
	else return notify_fail("��Ҫ�������\n");
}

int do_liao(string arg)
{
	object me = this_player();

	if (me->is_fighting() || me->is_busy())
		return notify_fail("����æ���ء�\n");
	if (me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("����������û���ܵ��κ��˺���\n");
	if ( (int)me->query_condition("bed_poison") > 0 )
	{
		me->receive_wound("qi", 10);
		message_vision(HIR "$NͻȻֻ��һ���溮�������壬������������ʱ��̫�̣�������δ��ԭ֮�ʡ�\n"NOR, me);
		me->unconcious();
		return 1;
	}
	if (arg == "bed" || arg == "chuang")
	{
		message_vision(HIY"$N���Ϻ��񴲣�Ҫ��ǧ�꺮�����ˡ�\n"NOR, me);
		if (me->query_skill("yunv-xinfa", 1) < 40)
			return notify_fail("�����������Դ������Ů�ľ��ڹ��ศ�������޷����ơ�\n");
		me->set("eff_qi", me->query("max_qi"));
		me->apply_condition("bed_poison", 25);
		return 1;
	}
	return notify_fail("��Ҫ���������ˣ�\n");
}
