inherit ITEM;
inherit F_LIQUID;

#include <ansi.h>

void create()
{
        set_name(HIY "����������" NOR, ({"soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������˱ǵ���������\n");
                set("unit", "��");
                set("value", 80);
                set("max_liquid", 4);
        }

        set("liquid", ([
    	        "type": "water",
                "name": "������",
                "remaining": 6,
                "drunk_supply": 20,
        ]));
}

