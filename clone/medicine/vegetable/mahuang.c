// mahuang.c ���

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"���"NOR, ({"mahuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 32);
		set("value", 100);
		set("nostrum", 16);
		set("long", "����һ����ƣ���˵������ҩ��\n");
		set("value", 1000);
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

	write("��Ʋ�����ô�ԡ�\n");
	return 1;
}
