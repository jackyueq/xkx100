// Obj: /d/lingxiao/obj/mei.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

string *names = ({
	HIW"÷��"NOR,
	HIG"÷��"NOR,
	CYN"÷��"NOR,
	HIC"÷��"NOR,
	HIY"÷��"NOR,
	HIR"÷��"NOR,
});
void create()
{
	int i = random(sizeof(names));
	set_name(names[i], ({"mei hua","hua"}));
			set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", HIW"һ��÷����\n");
		set("value", 0);
		set("material", "plant");
		
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
	}
	setup();
}

