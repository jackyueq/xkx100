// item: redobj.c

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIR"�첼С��"NOR, ({"hongbu xiaonang", "xiaonang"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һֻ�첼С�ң���֪����ʲô�ô���\n");
                set("unit", "ֻ");
                set("value", 1);
        }
}

void init()
{
}
