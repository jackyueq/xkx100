
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "������" NOR, ({"hdzuiji"}));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�����˱ǵ�һֻ��������\n");
                set("unit", "ֻ");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 20);
                set("cook_msg", "
$N����ϴ�������࣬նȥ��ͷ���š�Ȼ�������ˮ�����½�Ƭ��
�жΡ��˽ǣ���ˮ�ٶȷ��𣬷ż���ˮ�н�������ΪΪֹ���ٽ�
��ȡ�����䣬����ʢ��������ڣ������ζ�ϼ�ͬ�����Ķ���ˮ
���ȣ�������Ƽ��룬��Ϊ��±����󽫼���ȡ��ն��С�飬��
���ϵ������Ͼ�±��\n\n"
		);                
        }
}
