// muchui.c ľ��

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("ľ��", ({ "hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
			set("long", "һ�����úܾ��µĶ̴���\n");
		set("value", 3);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_hammer(2);
	setup();
}
