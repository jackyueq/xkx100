#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIM "���˭������÷" NOR, ({"yudiluomei"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������Ũ������ţ������ÿ��ţ�ⶼ��������С����ƴ�ɡ�\n");
                set("unit", "��");
                set("value", 120);
                set("food_remaining", 10);
                set("food_supply", 100);
                set("cook_msg", "
$Nȡ��С��ȵ�������Ρ�С����䡢Сţ���ӡ����������⣬
�ֱ𷴸����������ã�ȥ��hĤ��ȡ��������С������غ�ƴ
�����״������С���Ͽ���\n\n");                
        }
}
