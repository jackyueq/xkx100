// pond5.c

#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIY"�ϳ�"NOR, ({ "lao chi", "chi","lao" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"һ��ˮɫΪ�ϵĳ�̶��\n"NOR);
		set("value", 1);
	}
}

int is_container() { return 1; }

