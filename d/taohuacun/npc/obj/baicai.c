#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "�ײ�" NOR,({"baicai"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ײˡ�\n");
                set("unit", "��");
        }
}