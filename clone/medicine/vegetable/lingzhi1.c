// lingzhi1.c ��֬

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIG"��֬"NOR, ({"lingzhi"}));
	set_weight(500);
	set("vegetable", 8);
	set("value", 1200);
	set("nostrum", 2);
	set("unit", "��");
	set("long", "����һ�麣������֬������������ҩ��\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	write("��֬�������ԡ�\n");
	return 1;
}
