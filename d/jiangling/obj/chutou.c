#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("��ͷ", ({ "chu tou", "chu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ũ���ֵ��õĳ�ͷ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N��$n�Ӽ��Ϸ����������������С�\n");
                set("unwield_msg", "$N��$n���ڼ��ϡ�\n");
        }

        init_hammer(25);
        setup();
}

