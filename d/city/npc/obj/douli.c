// douli.c ����

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
	set_name(BLK "��¨����" NOR, ({"dou li"}) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����������������Χ���ټӺ����Է��ꡣ����֮ȡ����㣬����ȡ������Ҳ��\n");
		set("value", 600);
		set("unit", "��");
		set("armor_prop/armor",2);
		set("armor_prop/personality", 5);
		set("wear_msg","$N����һ��$n��\n");
		set("unequip_msg", "$Nժ��ͷ�ϵ�$n���������\n");
	}
	setup();
}
