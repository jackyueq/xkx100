// chantui.c ����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(YEL"����"NOR, ({"chantui"}));
	set_weight(500);
	set("vegetable", 1);
	set("value", 2000);
	set("nostrum", 32);
	set("unit", "Ƭ");
	set("long", "����һƬ��ɵĲ��ɣ�����������ҩ��\n");
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

	write("���ɱ�����ҩ���ܳԡ�\n");
	return 1;
}
