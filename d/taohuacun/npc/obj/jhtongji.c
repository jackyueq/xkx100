#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(YEL"�л�ͯ��"NOR, ({"jhtongji"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "һֻ���������ͣ���ζ�˱ǵĽл�����\n");
                set("unit", "ֻ");
                set("value", 120);
                set("food_remaining", 1);
                set("food_supply", 100);
                set("cook_msg", "
$N����ĸ����ɱ��ϴ�ɾ����߿�ȡ �����࣬����ɽ�Ρ��˽ǡ�
���͡��ܾơ����ǡ����Ρ�ζ�����жΡ���˿�ͳ� ��±֭���գ�
�������������͡���Ҷ������ֽ����ϸ�������ã��������ٰ� 
�Ϻͺõľ�̳�������Ͼơ����Σ��濾����ʱ����[����]ȥ 
�����պ�����Ρ���������ʳ��\n\n"
		);                
        }
}
