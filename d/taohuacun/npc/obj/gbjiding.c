
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "��������" NOR, ({"gbjiding"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������ϸ�ۣ������������Դ�����Ĺ���������\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$Nȡ�۹������⣬���ϻ����гɷ������ý��͡����Ρ�
ʪ����Ͻ�������ɺ��������������г�ɢ������С�
�����⡢�컨���ף��������ǡ��ס� �Ρ�ζ������
�����ͳɵ���֭��\n\n"
		);                
        }
}
