//shenxiandan.c ���ɵ�
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
	set_name(HIY"��"HIG"��"HIR"��"NOR, ({"shenxian dan", "xian dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 54);
		set("nostrum", 38);
		set("level", 120);
		set("long", "����һ�������ɾ��ĵ�ҩ����Ϻ�������ɲ��ɾ�֮������
��ʱ������ʮ���죬�����֮�����ƶ��ɡ�\n");
		set("value", 50000);
	}
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
	if(arg=="dan") 
	{
          /*	if(me->query("eff_jing") >= me->query("max_jing") &&
			me->query("eff_qi") >= me->query("max_qi") )
		{
			write("û��û���ģ����˷���ô����ҩ����\n");
			return 1;
		}*/
		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->set("neili",me->query("max_neili"));
		me->set("tili",me->query("max_tili"));
message_vision(HIG"$N����һ�����ɵ���һ��������ˬ�ӵ���������ȫ����ɢ��ɲʱ�������
�������������������ŷ���\n"NOR,me);
		me->start_busy(1);
		destruct(this_object());
	}
	return 1;
}

