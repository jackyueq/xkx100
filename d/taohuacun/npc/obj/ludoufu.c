
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "±����" NOR, ({"ludoufu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɢ����Ũ���±������\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                set("cook_msg", "
$N���ƶ��������ط�����ˮ����Ǻù��ǣ��������󵽶�������
���С�ס�������״ʱȡ�����ٽ������ÿ�ˮ��һ�£��԰�ȥ
Ѫˮ��Ȼ���𾻸ɹ������������룬�ٽ����ŷ��ڶ������棬����
�������͡��ǡ���С�»���Լ��ʮ���ӣ���󽫶���ȡ�����г�Ƭ��\n\n"
		);                
        }
}
