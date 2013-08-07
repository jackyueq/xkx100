// Pill: bicanfeng.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"�̲Ϸ�"NOR, ({"bican fen", "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���綾�Ķ�ҩ, ��������������м�Ѫ���֮Ч. \n");
		set("unit", "��");
		set("value", 20000);
	}
	set("pour_type", "1");
	setup();
}

int init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	message_vision("$N��ͷ��һС��" + name() + "��������ȥ��\n", me);
	me->set_temp("die_reason","���±̲Ϸۣ���ɱ������");
	me->die();
	destruct(this_object());
	return 1;
}
