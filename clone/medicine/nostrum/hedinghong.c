// Pill: hedinghong.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"�׶���"NOR, ({"heding hong", "hong"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һƿ�綾�Ķ�ҩ, ��������������м�Ѫ���֮Ч. \n");
		set("unit", "ƿ");
		set("value", 20000);
	}
	set("pour_type", "1");
	setup();
}

int init()
{
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}

int do_drink(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ȣ�С�ı�Ǻ���ˡ�\n");

	message_vision("$N��ͷ��ཹ�ཹ���һƿ" + name() + "��\n", me);
	me->set_temp("die_reason","���º׶��죬��ɱ������");
	me->die();
	destruct(this_object());
	return 1;
}
