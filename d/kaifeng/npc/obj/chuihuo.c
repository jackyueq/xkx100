#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("�����", ({"chui huoguan","guan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("long","��һ�˴���,ʹ�����ʢ�����.\n");
                set("material", "wood");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_staff(5);
        setup();
}
