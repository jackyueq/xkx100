// tianwangdan.c ����������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
        set_name("����������", ({"baoming dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 4000);
                set("long", "������������������������ɽ�˲Ρ����ܵ���ѩ���������ɵ��鵤��\n");
                set("medicine", 1);
                set("no_drop", "�������������ƣ��������ӣ� \n");
        }

        setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ( me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi"))
	{
		message_vision("$Nû��Ҫ��������������\n",me);
	}
	else
	{
		me->receive_curing("jing", 250);
		me->receive_curing("qi", 400);
		message_vision("$N����һ����������������ʱ���úö��ˡ�\n",me);
		destruct(this_object());
	}
	return 1;
}
