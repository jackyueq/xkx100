#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW "�׻�Ƥ��" NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ð׻�Ƥ�������Ķ̰���\n");
                set("value", 50000);
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}

