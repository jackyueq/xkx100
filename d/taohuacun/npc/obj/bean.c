#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(CYN "����" NOR,({"bean"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ꡣ\n");
                set("unit", "��");
        }
}