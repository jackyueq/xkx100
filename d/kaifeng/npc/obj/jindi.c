#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY "���" NOR, ({ "jin di", "jin", "di" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "һ���ɴ�������ĵ��ӣ����������������ԡ�\n" NOR);
                set("value", 25000);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "��������һ������������У�������Ū��\n" NOR);
                set("unwield_msg", HIY "$N" HIY "΢΢һЦ�������еĽ�Ѳ�����䡣\n" NOR);
        }
        init_sword(30);
        setup();
}
