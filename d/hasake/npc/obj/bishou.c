#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("ذ��", ({ "bishou", "dao" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����λε�ذ��\n");
                set("value", 500);
                set("material", "steel");                
        }
        init_blade(15);
        setup();
}

