// sangye.c ɣҶ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIG"ɣҶ"NOR, ({"sangye"}));
	set_weight(500);
	set("vegetable", 8);
	set("value", 15);
	set("nostrum", 64);
	set("unit", "Ƭ");
	set("long", "����һƬ���ɵ�ɣҶ������������ҩ��\n");
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

	write("��Ȳ�����˿�Ĳϣ�Ҳ���ǳԲݵ����ӣ���ô��������Ȥ��\n");
	return 1;
}
