#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB "����������" NOR, ({ "luowen hai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIB "����ɫ�����ⶼ�������ε����ơ�\n" NOR);
                set("value", 1500);
        }
}
