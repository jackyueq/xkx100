
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(HIY "����" NOR,({"liyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һβ������������㡣\n");
                set("unit", "β");
        }
}