#include <ansi.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit EQUIP;

void create()
{
        set_name(HIM"���˿��"NOR, ({"souyun sipao", "sipao", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������濾꣬�����˿���������Ų���ɫ��˿�ۡ�\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
                set("unit", "��");
                set("value", 1000);
                set("material", "crimsonsteel");
                set("armor_prop/armor", 100);
                set("armor_prop/dodge", 50);
                set("armor_prop/spells", 30);
             }
}
