// gancao.c �ʲ�

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"�ʲ�"NOR, ({"gancao"}));
	set_weight(500);
	set("vegetable", 2);
	set("value", 10);
	set("nostrum", 16);
	set("unit", "֧");
	set("long", "����һ֧�ж��˵ĸʲݣ�����������ҩ��\n");
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

	write("��һ�ھͰѸʲݳ�����ȥ��������һ�����\n");
	destruct(this_object());
	return 1;
}
