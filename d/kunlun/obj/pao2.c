// Room: /d/kunlun/obj/pao2.c
// Last Modified by winder on Nov. 14 2000

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIC "�ױ���ɫ����" NOR, ({ "chang pao", "cloth","changpao","pao"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ����ɫ����������ϸ����ɫ���ۣ�����������ʲô���ϲóɵġ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 45);
		set("value", 100);
		set("wear_msg","$N��$nӭ��һչ���������������ϡ�\n");
		set("remove_msg","$N����İ�$n����������������\n");
	}
	setup();
}
