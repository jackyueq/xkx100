// ganmao.c ��ðҩ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW"��Ч��ðҩ"NOR, ({"texiao yao", "ganmao yao","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����Ч��ðҩ���õ���ƽһָ�Ķ����䷽��\n"+
		"�Ը��ָ�ð��֢����������Ч��\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return 0;
	if (me->is_busy() )
		return notify_fail("�𼱣���������\n");
	if (! me->query_condition("ill_kesou") && 
	! me->query_condition("ill_shanghan") &&
	! me->query_condition("ill_fashao") &&
	! me->query_condition("ill_dongshang") &&
	! me->query_condition("ill_zhongshu") )
	{
		write("��������û�и�ð�����ҳ�ҩ��\n");
		return 1;
	} 
	else 
	{
		me->clear_condition("ill_kesou");
		me->clear_condition("ill_shanghan");
		me->clear_condition("ill_fashao");
		me->clear_condition("ill_dongshang");
		me->clear_condition("ill_zhongshu");
		message_vision(HIY"$N����һ����Ч��ðҩ����ð֢״��������ࡣ\n"NOR, me);
		me->start_busy(3);
		destruct(this_object());
		return 1;
	}
}
