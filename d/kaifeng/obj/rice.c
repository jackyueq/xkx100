inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
        set_name(HIW "����С����" NOR, ({ "rice", "fan" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ڵ�С���ࡣ\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
                set("material", "rice");
        }
        setup();
}

