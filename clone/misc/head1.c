// head.c -�Դ�
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(RED"ͷ­"NOR, ({ "head"}));
        set_weight(300);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("value", 10);
            set("long",RED"һ����Ѫ���ܵ��׼����뷢ɢ�ң���Ѫ������������\n"NOR);
        }
}
