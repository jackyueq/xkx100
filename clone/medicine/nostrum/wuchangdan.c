//wuchangdan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIR"�޳���"NOR, ({"wuchang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�Ө�����޳��������һ������������ƣ�
����������֮����\n");
		set("value", 50000);
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int fw;
	int force_limit, neili_limit, force_skill, add_skill, improve;
	int nowcondition;

	object me = this_player();

	force_limit = me->query_skill("force", 1)*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if(me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") )
	{
		message_vision(HIG"$N����һֻ�޳�����ֻ��ȫ������������㲹ҩ��̫���ˣ�����������ˣ�\n" NOR, me);
		me->receive_damage("jing",30);
		me->receive_damage("qi",50);
		me->receive_wound("jing",20);
		me->receive_wound("qi",40);
	}
	else
	{
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		message_vision(HIR"$N����һ���޳�����һ�������ӵ������𣬶�ʱȫ�����������\n"NOR,me);
	}
	destruct(this_object());
	me->start_busy(2);
	return 1;
}

