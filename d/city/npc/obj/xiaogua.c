//Cloth :xiaogua.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("��ɴС��", ({ "xiao gua", "cloth"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɴ���Ĺ��ӣ���С�˵㣬������ͯװ��\n");
		set("value", 60);
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("kidonly", 1);
	}
	setup();
}
