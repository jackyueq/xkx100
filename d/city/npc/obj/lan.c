// lan.c ����

inherit ITEM;
#include <ansi.h> 

void create()
{
        set_name(HIY"����" NOR, ({ "li lan", "lan" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һֻװ����������ӣ�ϸ�ﾫ�ƶ��ɣ����տ��治��\n");
                set("value", 1000);
        }
}

int is_container() { return 1; }
