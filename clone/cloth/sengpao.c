// sengpao.c
// Last Modified by winder on May. 25 2001
 
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("ɮ��", ({ "seng pao", "pao", "cloth" }) );
	set("long", "����һ��Ѱ����ɮ�ۣ��Ǻ����ǵ���ͨװ����\n");     
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/spells", 5);
	}
	setup();
}

