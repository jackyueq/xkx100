#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIM"�һ�"NOR, ({"leaf", "flower"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIM"����һ֦���޵��һ���\n"NOR);
		set("unit", "֦");
		set("value", 100);
	}
}
