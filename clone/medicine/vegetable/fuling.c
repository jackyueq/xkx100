// fuling.c ����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(YEL"����"NOR, ({"fuling"}));
	set_weight(500);
	set("vegetable", 2);
	set("value", 100);
	set("nostrum", 8);
	set("unit", "��");
	set("long", "����һ����͵����ߣ�����������ҩ��\n");
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

	write("���������ڰ����߳�����ȥ��\n");
	destruct(this_object());
	return 1;
}
