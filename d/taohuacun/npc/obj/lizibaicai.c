
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW "���Ӱǰײ�" NOR, ({"lizibaicai"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����Ӱǰײˡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N�����ϴ���д��,����ȥ������ˮ������͸,�˸�ˮ�ݡ�
�ٽ���������ϴ��ȥ�١�������Լ������,����׷��³���,
�����ζ�ϡ����������ӡ�����Ƭ�Ļ�������͸��������
����ˮ���͡�\n\n"
		);                
        }
}
