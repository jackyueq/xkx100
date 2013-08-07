#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("����֮��", ({"guai shedan", "dan", "shedan"}));
        set("unit", "ֻ");
        set("long", "���ǹ��ߵĵ���ԲԲ�ģ�������ɫ���ȳ��ޱȣ���֪��û�ж���\n");
        set("value", 1000);
        setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit,food_limit,water_limit;
	object me=this_player();
	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	food_limit = me->max_food_capacity();
	water_limit = me->max_water_capacity();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if (( me->query("food")>=food_limit)||(me->query("water")>=water_limit))
		return notify_fail("���Ѿ��Ա��ˣ���Ҳ�Բ����κ�һ�㶫����\n");
	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 2);
		me->add("neili", 5);
	}
	message_vision(HIY "$N����һ���ߵ���ֻ��֭Һ�ȼ��༫���ѳ��ޱȣ�ֻ�����˳�ȥ��\n" NOR, this_player());
	me->add("food",50);
	me->add("water",50);
	destruct(this_object());
	return 1;
}
