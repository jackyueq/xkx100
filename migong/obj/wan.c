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
        set_name(HIG"�Ż���¶��"NOR, ({"jiuhuayulu wan", "jiuhua wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ž�Ө���̵ľŻ���¶�裬���һ������������ƣ�
����������֮����\n");
                set("value", 500000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");
	
                fw = (int)me->max_food_capacity();
                me->set("food", fw);
                fw = (int)me->max_water_capacity();
                me->set("water", fw);
		me->set("jing",me->query("max_jing"));
		me->set("qi",me->query("max_qi"));
		me->set("eff_jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("neili",me->query("max_neili"));
me->start_busy(5);
message_vision(HIG"$N����һ�žŻ���¶�裬һ��������ˬ�ӵ���������ȫ����ɢ��\n"NOR,me);
		
        	destruct(this_object());
	return 1;
}

