// da-shugan.c

#include <weapon.h>;
#include <ansi.h>;
inherit CLUB;

void create()
{
	set_name(HIY"������"NOR,({ "da shugan", "shugan" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "bamboo");
		set("long", "����һ���ɵ��ĵĴ����ɡ�\n");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_club(8);
	setup();
}
