// ycloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"�����"NOR, ({ "yellow magua", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���Ǽ�����ӣ��ǵ������ͣ�������ҫ�����Զ��衣\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 150);
		set("armor_prop/personality", 3);
	}
	setup();
}
