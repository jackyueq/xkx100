#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"����Ϻ��"NOR, ({"ljxiaren"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ŨŨ��һ������Ϻ�ʡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("cook_msg", "
$N����Ϻϴ��������Ϻ�ʣ��õ��塢���Ρ�ʪ��۽��ã�
ȡ�����²������÷�ˮ���ݣ����õ�Ϻ�����ĳ��ȵĴ���
���죬�����ϲ�Ҷ����֭���ܾƷ�����\n\n"
		);                
        }
}
