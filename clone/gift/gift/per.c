#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( HIC "���յ�" NOR, ({ "yangyan dan", "yangyan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ�����յ�����˵���˿���������ò��\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "per");
                set("gift_name", "������ò");
                set("gift_point", 75);
                set("gift_msg", HIM "��������Ϸ���������ı仯�����漴��ƽ����������\n" NOR);
        }
        setup();
}

