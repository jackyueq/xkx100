// xuejie.c Ѫ��

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(RED"Ѫ��"NOR, ({"xuejie"}));
	set_weight(800);
	set("vegetable", 32);
	set("value", 400);
	set("nostrum", 2);
	set("unit", "��");
	set("long", "����һ���ʺ��Ѫ�ߣ�����������ҩ��\n");
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

	write("���������ڰ�Ѫ�߳�����ȥ��\n");
	destruct(this_object());
	return 1;
}
