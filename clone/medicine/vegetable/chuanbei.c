// chuanbei.c ����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(RED"����"NOR, ({"chuanbei"}));
	set_weight(500);
	set("vegetable", 1);
	set("value", 500);
	set("nostrum", 64);
	set("unit", "��");
	set("long", "����һ�������۵Ĵ���������������ҩ��\n");
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

	write("���������ھͰѴ���������ȥ��\n");
	destruct(this_object());
	return 1;
}
