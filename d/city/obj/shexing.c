// shexing.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIC"������"NOR, ({"shexing zhang", "zhang"}) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����γ��ȣ���ŷ���˵ı�����\n");
		set("value", 50000);
		set("material", "steel");
		set("wield_msg", "��ಡ���һ����$N�����Ѷ���һ��$n��\n");
		set("unwield_msg", "����ǰһ����$N���е�$n�Ѳ����ˡ�\n");
	}

	init_staff(30);
	setup();
}

