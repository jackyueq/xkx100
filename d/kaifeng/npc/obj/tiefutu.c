#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "��ͭ����" NOR, ({ "futu" }) );
        set_weight(500000);
        set_max_encumbrance(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ƿ����еĸ������������Ž�վ���\n");
                set("value", 50);
        }
}
