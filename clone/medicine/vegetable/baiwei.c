// baiwei.c ��ޱ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"��ޱ"NOR, ({"baiwei"}));
	set_weight(500);
	set("unit", "��");
	set("value", 1200);
	set("vegetable", 1);
	set("nostrum", 2);
	set("long", "����һ��ʢ���İ�ޱ������������ҩ��\n");
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

	write("��һ�ھͰѰ�ޱ������ȥ��\n");
	destruct(this_object());
	return 1;
}
