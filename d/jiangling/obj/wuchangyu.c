#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"����"HIR"�����"NOR, ({"wuchang yu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǡ��ļ�����ׯ����һ�����ˣ���������������ƶ��ɣ��������ð��������\n");
                set("unit", "��");
                set("value", 800);
                set("food_remaining", 10);
                set("food_supply", 100);
        }
}

