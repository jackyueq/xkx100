#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIG"����"HIW"����"HIY"��"NOR, ({"tianma soup"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                           set("long", "���ǡ��ļ�����ׯ����һ�����ˣ��������ð��������\n");
                set("unit", "��");
                set("value", 800);
                set("max_liquid", 30);
             }
                set("liquid", ([
                    "name" : HIG"����"HIW"����"HIY"��"NOR,
                    "remaining" : 8,
                    "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

