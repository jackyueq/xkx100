// redbag.c ���

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIR"���"NOR, ({ "redbag", "bag" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��װ��ѹ��Ǯ�ĺ�����Ĺ����ҵز�֪����ʲô�ö�����\n\n    "HIR"����ã���\n\n"NOR); 
                set("value", 0);
        }
}

int is_container() { return 1; }


