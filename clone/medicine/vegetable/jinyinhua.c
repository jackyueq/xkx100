// jinyinhua.c ������

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(YEL"��"HIW"��"HIY"��"NOR, ({"jinyinhua"}));
	set_weight(500);
	set("vegetable", 4);
	set("value", 30);
	set("nostrum", 16);
	set("unit", "��");
	set("long", "����һ���Ľ�����������������ҩ��\n");
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

	write("��������ҩ������ڡ�\n");
	return 1;
}
