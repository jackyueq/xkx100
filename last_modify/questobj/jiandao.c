// jiandao.c �嶾��
#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name("�嶾��", ({ "jian dao", "gou" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ű���������һֻ�����������ι�˾綾��\n"
);
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        setup();
}