// guijia.c �ڹ��

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIB"�ڹ��"NOR, ({"gui jia","jia"}));
	set_weight(800);
	set("vegetable", 2);
	set("value", 300);
	set("nostrum", 64);
	set("unit", "��");
	set("long", "����һ���ڹ�ף������и��ֻ��ƣ�����������ҩ��\n");
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

	write("�㲻�������Ϳй�ס�\n");
	return 1;
}
