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
        set_name(HIG"�ٲݵ�"NOR, ({"baicao dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������ҩ�ﾫ�ƶ��ɵĵ�ҩ��������ҩЧ��\n");
                set("value", 500000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
          if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	
	if(arg=="dan") 
	{
                fw = (int)me->max_food_capacity();
                me->set("food", fw);
                fw = (int)me->max_water_capacity();
                me->set("water", fw);
	 	me->set("neili",me->query("max_neili")*2);
message_vision(HIG"$N����һ�Űٲݣ���ʱֻ�����������������\n"NOR,me);
		me->start_busy(1);
        	destruct(this_object());
	}
	return 1;
}

