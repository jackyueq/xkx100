#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( WHT "��ʶ��" NOR, ({ "danshi dan", "danshi", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ�ŵ�ʶ������˵���˿������ӵ�ʶ��\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "cor");
                set("gift_name", "���쵨ʶ");
                set("gift_point", 75);
                set("gift_msg", HIM "��������巢����һЩ�仯�����漴��ƽ����������\n" NOR);
        }
        setup();
}

