
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "������Ƭ" NOR, ({"shanpian"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ı�����Ƭ��\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N������ƽ��������ϣ�����ǩ�ض�Ƥ������Ƭ��ȥ���ǣ�
ȥƤ��ȥβ�� �ýྻ�����ɣ���Ҫ��ˮϴ������Ӱ����ζ��
Ȼ���гɺ�ҶƬ���ٿ����������͹���������Ƭ����ȥ�࣬
��������ȥ�͡��ڹ�����������������ȣ�������ͷ���飬
������ڳ��㣬����������ۡ��Ρ������ͣ��ٽ���Ƭ��
���Գ����������ͣ����Ϻ����ۡ�\n\n"
		);                
        }
}
