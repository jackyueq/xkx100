// chuanshanjia.c ��ɽ��

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(GRN"��ɽ��"NOR, ({"chuanshanjia"}));
	set_weight(500);
	set("vegetable", 2);
	set("value", 1000);
	set("nostrum", 1);
	set("unit", "ֻ");
	set("long", "����һֻ���ƹ��Ĵ�ɽ�ף�����������ҩ��\n");
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

	write("��ɽ�׳Բ��á�\n");
	return 1;
}
