// mangguzhuha.c

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(NOR"ç��"HIR"��"NOR"��", ({"ha"}));
	set("unit", "ֻ");
	set("value", 40000);
	set("long","ç�����������ү�������Ҳ��˵˵���ˡ�����������ʨ�ӣ��������������̫���Ͼ�����ţ����ç���������֮������ͨ��󣬶��������������ഫ����˵���������������\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() || random(2)==1 )
		return notify_fail("�𼱣������ԣ�С�ı����ˡ�\n");

	message_vision(HIG"$N����һֻ"+name()+HIG"���پ�����������ȫ��ί�ٽ�����ȥ��\n" NOR, me);
	if (me->query_condition("drunk"))
		me->apply_condition("drunk",0);
	if (me->query_condition("flower_poison"))
		me->apply_condition("flower_poison",0);
	if (me->query_condition("ice_poison"))
		me->apply_condition("ice_poison",0);
	if (me->query_condition("iceshock"))
		me->apply_condition("iceshock",0);
	if (me->query_condition("rose_poison"))
		me->apply_condition("rose_poison",0);
	if (me->query_condition("sanxiao_poison"))
		me->apply_condition("sanxiao_poison",0);
	if (me->query_condition("scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	if (me->query_condition("slumber_drug"))
		me->apply_condition("slumber_drug",0);
	if (me->query_condition("snake_poison"))
		me->apply_condition("snake_poison",0);
	if (me->query_condition("ss_poison"))
		me->apply_condition("ss_poison",0);
	if (me->query_condition("xx_poison"))
		me->apply_condition("xx_poison",0);
	if (me->query_condition("zhua_poison"))
		me->apply_condition("zhua_poison",0);
	me->start_busy(2);
	destruct(this_object());
	return 1;
}
