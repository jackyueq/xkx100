// taohuaban.c �һ���

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIM"�һ���"NOR, ({"taohuaban"}));
	set_weight(500);
	set("vegetable", 16);
	set("value", 40);
	set("nostrum", 16);
	set("unit", "Ƭ");
	set("long", "����һƬ��ɱ�����һ��꣬����������ҩ��\n");
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

	write("�˼�ֻ���۷�ͺ����Ի�������Ȥ��ԭ����Ҳ......\n");
	return 1;
}
