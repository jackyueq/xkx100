// shadai.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "ɳ��", ({ "sha dai", "shadai" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ɳ��������װ������ɰ��������ϰ�Ṧ��\n");
		set("value", 6000);
		set("material", "wrists");
		set("armor_prop/armor", 5);
		set("shaolin",1);
		set("wear_msg",YEL"$N�ó�һ��ɳ���������ϡ�\n"NOR);
		set("remove_msg",YEL"$N��ɳ��������ȡ��������\n"NOR);
	}
	setup();
}
