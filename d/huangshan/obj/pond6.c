// pond6.c

#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name(HIG"����"NOR, ({ "feicui chi", "chi", "feicui" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"һ��ˮɫΪ���ĳ�̶��\n"NOR);
                set("value", 1);
        }
}

int is_container() { return 1; }

