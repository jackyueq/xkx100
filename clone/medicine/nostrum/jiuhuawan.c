//jiuhuawan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIG"�Ż���¶��"NOR, ({"jiuhuayulu wan", "jiuhua wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 54);
		set("nostrum", 38);
		set("level", 120);
		set("long", "����һ�ž�Ө���̵ľŻ���¶�裬���һ������������ƣ�
����������֮����\n");
		set("value", 50000);
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int fw;
	object me = this_player();

	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if(me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") )
	{
		write("û��û���ģ����˷���ô����ҩ����\n");
		return 1;
	}

	fw = (int)me->max_food_capacity();
//	me->set("food", fw);
	fw = (int)me->max_water_capacity();
//	me->set("water", fw);
 	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("max_jing"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
	me->set("neili",me->query("max_neili"));
	me->set("tili",me->query("max_tili"));
	message_vision(HIG "$N����һ�žŻ���¶�裬һ��������ˬ�ӵ���������ȫ����ɢ��\n"NOR,me);
	me->start_busy(1);
	destruct(this_object());
	return 1;
}

