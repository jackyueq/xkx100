// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( MAG"����"NOR, ({ "shou pa", "shoupa"}));
	set_weight(300);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",0);
		set("long","����һ���廨������\n");
	}
}
