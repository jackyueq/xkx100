// zheshan.c

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(YEL"��ֽ����"NOR, ({ "zhe shan", "shan" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������Ϊ�ǵ���ֽ���ȡ�\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ӻ����ͳ�һֻ$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ػ��\n");
        }
        setup();
}

