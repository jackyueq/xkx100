// hugu.c ����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(YEL"����"NOR, ({"hugu"}));
	set_weight(500);
	set("vegetable", 4);
	set("value", 30000);
	set("nostrum", 4);
	set("unit", "��");
	set("long", "����һ�鰾�ƹ��Ļ��ǣ�����������ҩ��\n");
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

	write("���ſй�ͷ���㲻�ǰɣ�\n");
	return 1;
}
