// baodi_kuaixue.c

#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("���׿�ѥ", ({"baodi kuaixue", "xue", "shoes"}));
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��˫ѥ�ӷ��ƾ�ϸ��������ɣ�������ʿ��������ѥ�ӡ�\n");
		set("unit", "˫");
		set("value", 200);
		set("material", "silk");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 10);
	}
	setup();
}
