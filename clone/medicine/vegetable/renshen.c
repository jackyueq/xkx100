// renshen.c �˲�

inherit ITEM;
#include <ansi.h>;
void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"�˲�"NOR, ({"ren shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 8);
		set("nostrum", 32);
		set("long", "����һ�걣���˺ܾõ�ǧ���˲Ρ�\n");
		set("value", 10000);
	}
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

	me->receive_curing("qi", 200);
	message_vision("$N����һ���˲Σ��پ�����һ����������ð��������\n",me);
	destruct(this_object());
	return 1;
}

