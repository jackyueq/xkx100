#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "��֬�̲��" NOR, ({ "bibo hai", "bibo", "hai"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIC "���̵Ĵɱ������ŵ����֬"
                            "��,���Ǵ��о�Ʒ��\n" NOR);
                set("value", 1500);
        }
}
