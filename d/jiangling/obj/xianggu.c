#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BLK"�㹽"HIY"�հ���"NOR, ({"xianggu banli"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǡ��ļ�����ׯ����һ�����ˣ��������ð��������\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

