#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "drink");
}


void create()
{
	set_name(HIW "����" NOR, ({"cheese"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������ң��������ҾͲ����������ԭ��\n");
		set("unit", "��");
               set("value", 5000);
             }
}

int do_drink(string arg)
{	
	object me = this_player();
	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;
        if(me->query("water") < me->max_water_capacity()){
	message_vision(HIG "$N��µ��µ�غ���һ��" + this_object()->query("name")+ HIG "��Ĩ��Ĩ�졣\n"NOR,me);
        if(me->query("food") < me->max_food_capacity())
           me->add("food", 100);
        me->add("water", 100);
       	destruct(this_object());       
	return 1;
        }
}

