// item: yellowobj.c

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIY"�Ʋ�С��"NOR, ({"huangbu xiaonan", "xiaonan"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һֻ�Ʋ�С�ң���֪����ʲô�ô���\n");
                set("unit", "ֻ");
                set("value", 1);
        }
}

