// baihudan.c �׻�������

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"�׻�������"NOR, ({"baihu duomingdan", "dan"}));
	set("unit", "��");
	set("vegetable", 39);
	set("nostrum", 20);
	set("level", 30);
	set("pour_type", "1");
	set("long", "����һ���׻���������ѩ��͸����\n");
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
		message_vision("$Nû��Ҫ�԰׻���������\n",me);
	}
	else
	{
		me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("eff_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("eff_qi"));
		me->set("neili",me->query("max_neili"));
		message_vision("$N����һ���׻���������ֻ��������̩ͨ��\n",me);
		destruct(this_object());
	}
	return 1;
}
