// Last Modified by winder on May. 25 2001
// niupi.c

#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("ţƤ��", ({"leather shield","shield", "jia", "armor"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("value", 1000);
                set("armor_prop/armor", 15);
        }
        setup();
}


