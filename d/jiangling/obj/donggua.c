#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC"���ϱ�ȹ��"NOR, ({"donggua"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǡ��ļ�����ׯ����һ�����ˣ�ѡ�÷������۱�ȹ�ߺ��۶��ϣ��ټӼ������������ɡ�\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 1);
                set("food_supply", 100);
        }
}

