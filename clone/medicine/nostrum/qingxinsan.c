// qingxinsan.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("����ɢ", ({"qingxin san", "san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������ɵ�����ɢ��רΪ���޽ⶾ֮�á�\n");
		set("vegetable", 9);
		set("nostrum", 35);
		set("level", 20);
		set("unit", "��");
		set("value", 1000);
	}
	set("pour_type", "1");
	setup();
}

int init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	message_vision("$N����һ��" + name() + "��\n", me);
	if ((int)me->query_condition("xx_poison") > 0)
	{
		me->apply_condition("xx_poison", 0);
	}

	destruct(this_object());
	return 1;
}
