
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "�Ǵ�����" NOR, ({"tcliyu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ƥ�����ۣ������������Ǵ����㡣\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N����ȥ�ۣ�����ȡ���࣬��ȥ������������������ĵ��������
�� ���Ρ�ζ�����պ󣬹�һ��ʪ��ۺ��������߳��ȵ�����ը�죬
��Ƥ���ֳʽ��ɫ�̳����ڷ�������ڣ��ٽ����ôС������⡢
���͡��ס����ǡ����Ρ�ζ��������������Ƴɵ���֭��\n\n"
		);                
        }
}
