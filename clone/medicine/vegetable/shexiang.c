// shexiang.c ����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIB"����"NOR, ({"shexiang"}));
	set_weight(500);
	set("vegetable", 16);
	set("value", 1600);
	set("nostrum", 8);
	set("unit", "��");
	set("long", "����һ��������������㣬����������ҩ��\n");
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

	write("����û���ֳԷ���\n");
	return 1;
}
