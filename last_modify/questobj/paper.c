// paper.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"��ɽ�۽�"HIR"Ӣ����"NOR, ({"yingxiong tie", "tie"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"��������������Լ��ƽ�Ӳμӻ�ɽ�۽������ᣬ���α�����е�������\n");
                set("material", "paper");
        }
}

