// Room: /d/kunlun/obj/pao1.c
// Last Modified by winder on Nov. 14 2000

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(WHT "�ڱ߰�ɫ����" NOR, ({ "chang pao", "cloth","changpao","pao"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ����ɫ���ߵİ�ɫ���ۣ������쳣����������ʲô�������ġ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 65);
		set("value", 100);
		set("wear_msg","$Nӭ��һչ��[�]��һ��������һ��$n��\n");
		set("remove_msg","$N�⿪$n,��$n����������������\n");
	}
	setup();
}
