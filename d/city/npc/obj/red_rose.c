// red_rose.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIR"��õ��"NOR, ({"red rose", "rose"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ�京�����ŵ�"HIR"��õ�塣\n"NOR);
                set("value", 1000);
                set("flower", 1);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}
