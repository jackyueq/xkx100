// poison: shedan.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
#include <ansi.h>;
int cure_ob(string);

void create()
{
	set_name("���ߵ�", ({"shedan", "dan"}));
	set("unit", "��");
	set("long", "����һֻ��ӨӨ�Ķ��ߵ���\n");
	set("value", 200);
	set("medicine", 1);
	setup();
}
int do_eat(string arg)
{
	int taoism_limit, jingli_limit;
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ((int)me->query_condition("snake_poison") > 7)
	{
		me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 5);
	}
	message_vision("$N����һ�����ߵ���һ��С��ҧ���ˣ��ÿ�Ŷ��\n",me);
	destruct(this_object());
	return 1;
}

