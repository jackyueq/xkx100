// heishidan.c ��ʯ�񶴵�

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIB"��ʯ�񶴵�"NOR, ({"heishi yudongdan", "dan"}));
	set("unit", "��");
	set("vegetable", 51);
	set("nostrum", 80);
	set("level", 100);
	set("value", 100000);
	set("long", "����һ���ܽ�ٶ��ĺ�ʯ�񶴵���\n");
	set("pour_type", "1");
	set("no_sell", 1);
	set("no_drop", 1);
	set("no_give", 1);
	set("no_get", 1);
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	message_vision(HIG"$N����һ����ʯ�񶴵���ֻ��һ�ɿ�ɬ����ζֱ͸���ܡ�\n" NOR, me);
	if (me->query_condition("chanchu_poison"))
		me->apply_condition("chanchu_poison",0);
	if (me->query_condition("scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	if (me->query_condition("slumber_drug"))
		me->apply_condition("slumber_drug",0);
	if (me->query_condition("snake_poison"))
		me->apply_condition("snake_poison",0);
	if (me->query_condition("xiezi_poison"))
		me->apply_condition("xiezi_poison",0);
	if (me->query_condition("zhizhu_poison"))
		me->apply_condition("zhizhu_poison",0);
	if (me->query_condition("zhua_poison"))
		me->apply_condition("zhua_poison",0);
	destruct(this_object());
	me->start_busy(2);
	return 1;
}
