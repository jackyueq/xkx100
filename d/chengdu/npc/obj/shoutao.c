// Room: /d/chengdu/npc/obj/shoutao.c
// Last Modifyed by Winder on Jan. 4 2002

#include <armor.h>
inherit HANDS;

void create()
{
	set_name( "Ƥ����", ({ "gloves", "pi shoutao", "shoutao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "����һ˫Ƥ���ף�������Ӳ����յĺۼ���\n");
		set("value", 4000);
		set("material", "leather");
		set("armor_prop/armor", 3);
	}
	setup();
}
