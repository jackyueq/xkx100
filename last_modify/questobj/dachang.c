// cloth.c
//
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIB"������"NOR, ({ "da chang" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ͺӥ����֯�͵Ĵ��. \n");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}

