// Room: /d/nanyang/npc/cloth.c
// Last Modified by winder on Nov. 20 2001

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("���г���", ({ "cloth" }) );
	set("long","һ������ɫ�ĳ��泤���������������ɡ�\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("value",1000);
		set("no_get",1);
		set("armor_prop/personality",1);
		set("armor_prop/armor", 1);
	}
	setup();
}
