// moyao.c ûҩ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"ûҩ"NOR, ({"moyao"}));
	set_weight(500);
	set("vegetable", 8);
	set("value", 300);
	set("nostrum", 8);
	set("unit", "��");
	set("long", "����һ������ҩ��-ûҩ������������ҩ��\n");
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

	write("���������ڰ�ûҩ������ȥ��\n");
	destruct(this_object());
	return 1;
}
