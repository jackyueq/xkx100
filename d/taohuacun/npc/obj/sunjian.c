#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "���" NOR,({"sunjian"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����⡣\n");
                set("unit", "��");
        }
}