// kandao.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("����", ({ "blade" }) );
   set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"һ�Ѵ󿳵���\n");
                set("unit", "��");
                set("value", 1000);
                set("material","wood");
        }
        init_blade(20);
        setup();
}

