// sanqi.c ����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIC"����"NOR, ({"sanqi"}));
	set_weight(500);
	set("vegetable", 16);
	set("value", 100);
	set("nostrum", 1);
	set("unit", "��");
	set("long", "����һ���������ߣ�����������ҩ��\n");
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

	write("������ҩ�ģ������ſھͳԡ�\n");
	return 1;
}
