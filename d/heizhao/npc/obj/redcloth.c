// item: redcloth.c

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIR"�첼"NOR, ({"hong bu", "bu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"����һ��첼������д��һ���ֵ������Ѵ˲��������̡�
��ɽ֮�󽫻�ɫ���ҽ���Сɳ�֡���\n");
                set("unit", "��");
                set("value", 1);
        }
}

