//lamei.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIW"��÷"NOR, ({"la mei", "mei"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֦");
                set("long",HIW
"һ֦��÷����������ؿ��ţ���ɢ�ŵ��ŵķҷ����϶�ʱ�֣�
��׵Ļ��������ź�������Ϯ�����Ե�׿Ȼ��Ⱥ�����ཿ�ġ�
���죬�Ͼ���Ҫ���ˡ�\n" NOR);
                set("value", 80);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ֦$n�����޼䡣\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }     
        setup();
}
