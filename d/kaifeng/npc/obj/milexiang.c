#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "�˱����շ���" NOR, ({ "xiang" }) );
        set_weight(500000);
        set_max_encumbrance(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����׺�����౦ʯ,���,�ƽ�����շ���.\n");
                set("value", 50);
        }
}
