#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIY "���˵�" NOR, ({ "xingyun dan", "xingyun", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ�����˵�����˵���˿������Ӹ�Ե��\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "kar");
                set("gift_name", "���츣Ե");
                set("gift_point", 75);
                set("gift_msg", HIM "��������Ϸ���������ı仯�����漴��ƽ����������\n" NOR);
        }
        setup();
}

