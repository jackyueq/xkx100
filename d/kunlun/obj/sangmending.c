// sanmending.c ɥ�Ŷ�

#include <weapon.h>
inherit THROWING;
// inherit COMBINED_ITEM;

void create()
{
	set_name("ɥ�Ŷ�", ({ "sangmen ding", "ding" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һõɥ�Ŷ����ƺ�ι���ǡ������޻����Ķ�֭��\n");
		set("value", 1);
		set("material", "steel");
		set("wield_msg", "$Nץ��һ��ɥ�Ŷ��������ġ�\n");
		set("unwield_msg", "$N�����е�ɥ�Ŷ��Ż�װ������Ƥ���\n");
		set("base_unit", "ö");
		set("base_weight", 2);
		set("poisoned", "qtlh_poi");
		set("poison_number", 6);
	}
	set_amount(random(5) + 10);
	init_throwing(10);
	setup();
}
