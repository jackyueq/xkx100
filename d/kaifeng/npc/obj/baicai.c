#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIG "��ײ�" NOR, ({"bai cai", "bai", "cai"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���ʵİײˡ�\n");
                set("unit", "��");
                set("value", 2);
                set("food_remaining", 1);
                set("food_supply", 5);
        }
        setup();
}
