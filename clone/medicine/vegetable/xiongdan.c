// xiongdan.c �ܵ�

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(GRN"�ܵ�"NOR, ({"xiong dan", "dan"}));
	set_weight(1000);
	set("vegetable", 16);
	set("value", 2400);
	set("nostrum", 64);
	set("unit", "��");
	set("long", "����һ�Ű���ɫ���ܵ�������������ҩ��\n");
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

	me->set("eff_qi", me->query("max_qi"));
	message_vision("$N����һ���ܵ������þ���ö��ˡ�\n", me);
	destruct(this_object());
	return 1;
}

