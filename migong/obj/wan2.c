inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIG"������"NOR, ({"wan"}));
	set("unit", "��");
	set("value", 200000);
	set("long", "���Ǻ����콾רΪ���������ƵĽⶾ����\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(arg=="wan") 
	{
message_vision(HIG"$N����һ�������裬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me);
		if (me->query_condition("xiezi"))
		me->apply_condition("xiezi",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("chanchu_poison"))
			me->apply_condition("chanchu_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("dragon_drug"))
			me->apply_condition("dragon_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("wugong_poison"))
			me->apply_condition("wugong_poison",0);
		if (me->query_condition("zhizhu_poison"))
			me->apply_condition("zhizhu_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
		destruct(this_object());
	}
	me->start_busy(2);
	return 1;
}
