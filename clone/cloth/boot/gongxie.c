// gongxie.c

#include <armor.h>
inherit BOOTS;
void create()
{
	set_name( "��Ь", ({"gong xie", "xie", "shoes"}));
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ˫խխ�Ĺ�Ь�������е���Ů�ǵĽ����\n");
		set("unit", "˫");
		set("value", 100);
		set("material", "silk");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 4);
		set("female_only", 1);
	}
	setup();
}
