// weiqi.c Χ��

#include <armor.h>

inherit ITEM;

void create()
{
	set_name("Χ��", ({ "wei qi", "weiqi", "qi", "go" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ��Χ�壬�����ô������ƣ������������ɡ�\n");
		set("value", 5000);
		set("material", "steel");
		set("armor_prop/armor", 10 );
	}
}

