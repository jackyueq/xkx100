#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIW"����"HIC"����"HIY"��"NOR, ({"zhenzhu soup"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǡ��ļ�����ׯ����һ�����ˣ��������ð��������\n");
                set("unit", "��");
                set("value", 1000);
                set("max_liquid", 50);
              }
                set("liquid", ([
                    "name" : HIW"����"HIC"����"HIY"��"NOR,
                    "remaining" : 10,
                    "type" : "water"
                ]) );
                set("liquid_type", "water");
                setup();
}

