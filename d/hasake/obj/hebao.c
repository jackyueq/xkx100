#include <armor.h>

inherit WAIST;

void create()
{
        set_name("�ɰ�", ({ "he bao", "hebao", "bao"}) );
        set_weight(500);
        set_max_encumbrance(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻСС�ĺɰ����������װһЩС������\n");
                set("material", "silk");
                set("no_get",1);
                set("armor_prop/parry", 1);
                set("value", 1000);
        }
        setup();
}

