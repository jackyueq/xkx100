#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "����Ŀ����" NOR, ({ "baitianmu ciwan", "ciwan", "bai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIW "�������,����ֽ���ϼѴ�����\n" NOR);
                set("value", 1500);
        }
}