#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"��Ƥ"NOR, ({"doupi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�����人�˰��Ե�һ��С�ԡ�\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

