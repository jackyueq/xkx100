// mifang.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;
void create()
{
        set_name(HIY"�׷�"NOR, ({ "mifang" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������׷���\n");
                set("unit", "��");
                set("value", 0);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}
