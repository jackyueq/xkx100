
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "��Ǯ��" NOR, ({"jqrou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɫ���ѵĽ�Ǯ�⡣\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("cook_msg", "
$N��������Ƭ�ɱ�Ƭ��ÿ��Ƭ��һ�߲��ϣ��ٽ���ʱ��г�һ����
����Ԫ��С��Բ���ӣ�һ������ý��͡��ǡ������ ���Ƶ��ɵ�±
�ڹ�һ�����ٷ�����Լ��ʮ���ӡ�Ȼ�� � ��һ���ؼ���û��Ƭ
�ϵ�����Ƭ�У�������ǩ���кõ��⴩��һ������Ĩ�ϸ���ۡ����
�������͹��������õ���Ƭ�������ը�죬��һƬƬ�ش���ǩ��ȡ��
���������װ�����С�\n\n"
		);                
        }
}
