// zhubang.c ���

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��ɽ��", ({ "pishanfu" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ɽ�����ƺ��൱��ʵ��\n");
                set("value", 200000);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_axe(300);
        setup();
}

