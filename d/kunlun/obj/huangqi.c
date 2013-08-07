// huangqi.c ����

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
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
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if ( (int)me->query_condition("medicine" ) > 0 )
	{
		me->add("qi", -100);
		me->add("neili", 100);
		message_vision(HIR "$N����һ����Σ�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	} else {
		me->add("qi", 50);
		message_vision("$N����һ����Σ�ֻ���û����������ڣ���ʱ�����˻�����\n", me);

		me->apply_condition("medicine", 30);
	}

	destruct(this_object());
	return 1;
}
