
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"���Ŷ���"NOR, ({"mpdoufu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɫ��ζ���������̵����Ŷ�����\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N�ѳ������л��ϣ��²������������ʱ�����ڣ��⳴��ˮ�����¶��꣬
������ζ�����Σ����ͣ�ͬʱ�������¶����������¹�����Լ�������´У�
��һ�죬����ˮ��۹��ͣ����װ�룬���������ϻ����档\n\n"
		);
        }
}
