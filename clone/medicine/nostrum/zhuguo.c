// zhuguo.c
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player()))
	{
		set("no_get", "�ٺ٣����ΰɣ�\n");
		set("no_drop", "����㶼���ӣ�\n");
	}
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIR "���" NOR, ({"zhu guo", "guo"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ͨ���ʺ죬һ����֪�ǲ��ɶ�õ���Ʒ��\n");
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

	me->set("qi", (int)me->query("eff_qi"));
	me->set("neili", (int)me->query("max_neili"));
	message_vision(HIR "$N����һ�������ֻ������ȫ����һ��ů���ӵ���ֱ��������\n"NOR,me);
	destruct(this_object());
	return 1;
}
