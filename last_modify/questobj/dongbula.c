//  instrument: dongbula.c
// Jay 3/18/96

#include <ansi.h>
inherit ITEM;
int do_play(string arg);

void init()
{
}

void create()
{
        set_name(HIG"������"NOR, ({"dongbula"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ά�����������������������������(play)����\n");
                set("value", 0);
        }
//        setup();
}
