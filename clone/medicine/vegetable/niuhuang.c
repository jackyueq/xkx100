// niuhuang.c ţ��

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"ţ��"NOR, ({"niuhuang"}));
	set_weight(500);
	set("vegetable", 8);
	set("value", 1000);
	set("nostrum", 16);
	set("unit", "��");
	set("long", "����һ��ţ����ȡ������ţ�ƣ�����������ҩ��\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	if (!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");

	if(arg=="niuhuang")
	{
		write("ţ�Ʋ�����ô�ԡ�\n");
	}
	return 1;
}
