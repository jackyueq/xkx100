#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC "�ʲ��㹽" NOR, ({"xcxianggu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���嵭������ζȴ��������ʲ��㹽��\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                set("cook_msg", "
$N���㹽����ˮ�Գ�ϴ�ɾ��ᣬ�ÿ�ˮ�������г����� 
Ȼ��������ͣ�������������Գ���������ˣ�������
��˱�ɫ�������кõ��㹽���Է����ᣬ���ε���ζ��
���÷��㹽��ˮ�����������ͷۣ����������֭��Ũ��\n\n"
		);                
        }
}
