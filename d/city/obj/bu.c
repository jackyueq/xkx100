// Last Modified by sir
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "�ٺõĲ�" , ({"bu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƥ");
                set("long", 
"����һƥ�ٺõĲ������Ѿ�����ֱ�ӱ���ȥ�ӹ��ˡ�\n");
                set("value", 1);
        }
        setup();
}
