// zanghonghua.c �غ컨

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIR"�غ컨"NOR, ({"zanghonghua"}));
	set_weight(500);
	set("vegetable", 32);
	set("value", 1700);
	set("nostrum", 8);
	set("unit", "��");
	set("long", "����һ������ѩ���ԭ�Ĳغ컨������������ҩ��\n");
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

	write("�ǵ�Τ��ү˵����ս�������ҩ������ȫ���Ѫ����Բغ컨ͼ��ɶ�ϣ�\n");
	return 1;
}
