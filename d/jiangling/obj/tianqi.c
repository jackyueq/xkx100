//Edited by fandog, 02/15/2000 

inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIB"����"NOR, ({"tianqi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������������ҩ�ġ�\n");
		set("value", 5000);
	}
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
	if ((int)me->query("jing") == (int)me->query("max_jing"))
		return notify_fail("�����ڲ���Ҫ��ҩ��\n");
	else {
		me->receive_curing("jing", 30);
		message_vision("$N����һ�����ߣ����������ö��ˡ�\n", me);
		me->start_busy(2);
		destruct(this_object());
		return 1;
	}
}

