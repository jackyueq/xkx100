// huangqi.c ����

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(YEL"����"NOR, ({"huang qi", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", YEL"����һ��ë���׵Ŀ��ŵ���ɫС���Ļ��Ρ�\n"NOR);
		set("value", 2500);
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

	if (me->query("eff_qi") == me->query("max_qi"))
	{
		me->receive_damage("qi", 50);
		message_vision(HIR "$N����һ����Σ�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ��û��ûʹ�ҳ�ҩ��ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else {
		me->receive_curing("qi", 50);
		message_vision("$N����һ����Σ�ֻ���û����������ڣ���ʱ��̹���ˣ�\n", me);
	}

	destruct(this_object());
	return 1;
}
