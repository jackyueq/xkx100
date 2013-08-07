// medicine: xuelian.c
// Last Modified by winder on Sep. 27 2001

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
	set_name("��ɽѩ��", ({"xuelian", "lian", "lotus"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 32);
		set("nostrum", 4);
		set("long", "����һ��ֻ���ں���ĵط�����������ѩ����\n");
		set("value", 100);
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

	if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
		return notify_fail("�����ڲ��ó��ⱦ����\n");
	me->receive_curing("qi",200);
	message_vision("$NС�ĵس���һ��ѩ������ʱ����������ˬ�˲��٣�\n", me);
	destruct(this_object());
	return 1;
}

