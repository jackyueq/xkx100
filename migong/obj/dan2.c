#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(BLU"������"NOR, ({"long dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������ڵ���\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("combat_exp", 2000);
	this_player()->add("potential",1000);
	message_vision("$N����һ��������,ֻ�����Լ��ֱ�������һЩ !\n", this_player());
	destruct(this_object());
	return 1;
}

