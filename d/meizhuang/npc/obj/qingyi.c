// qingyi.c
// Last Modified by winder on Sep. 27 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("��÷����", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

