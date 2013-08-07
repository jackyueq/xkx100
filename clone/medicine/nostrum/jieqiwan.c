// jieqiwan.c
inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(MAG"��ת������"NOR, ({"jieqi wan", "jieqi", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 15);
		set("nostrum", 82);
		set("level", 110);
		set("long","����һ��͸���Ϻ�ɫ���ľ�ת�����衣�������䵱��ҩ����߹�������Ч�ޱȡ�\n");
		set("value", 100);
		set("no_drop", "�������������뿪�㡣\n");
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	me->start_busy(2);
	if ( me->query_skill_mapped("force") != "taiji-shengong" )
	{
		me->add("max_neili", -10);
		message_vision(HIR "$N����һ�ž�ת�����裬ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
//		me->unconcious();
		me->start_busy(10);
	}
	else
	{
		if ( (int)me->query_condition("taoist_drug" ) > 0 )
		{
			me->add("max_neili", -1);
			message_vision(HIR "$N����һ�ž�ת�����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
		}
		else if ( neili_limit <= force_limit )
		{
			me->add("max_neili", 1);
			message_vision(HIG "$N����һ�ž�ת�����裬ֻ�������������ߣ����Ϲ���������\n͸ʮ����¥���鲼��������\n" NOR, me);
		}
		me->apply_condition("taoist_drug", 60);
	}
	destruct(this_object());
	return 1;
}

