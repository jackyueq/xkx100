// sifeng_kuanxue.c �ķ��ѥ

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("�ķ��ѥ", ({"sifeng kuanxue", "xie", "shoes"}));
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ˫���ƾ�ϸ�ĺ�ײ�Ь�����ʺϽš�\n");
		set("unit", "˫");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/dodge", 3);
	}
	setup();
}
