// zhike.c ֹ��ҩ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"ֹ��ҩ"NOR, ({"zhike yao", "zhikeyao","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ֹ��ҩ��\n");
		set("value", 2000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return 0;
	if (me->is_busy() )
		return notify_fail("�𼱣���������\n");
	if (! me->query_condition("ill_kesou"))
	{
		write("��������û�п��ԣ����ҳ�ҩ��\n");
		return 1;
	} 
	else 
	{
		me->clear_condition("ill_kesou");
		message_vision("$N����һ��ֹ��ҩ�����Ժö��ˡ�\n", me);
		me->start_busy(2);
		destruct(this_object());
		return 1;
	}
}
