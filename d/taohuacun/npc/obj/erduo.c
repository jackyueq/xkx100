#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC "С�����" NOR,({"erduo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��С����䡣\n");
                set("unit", "��");
        }
}