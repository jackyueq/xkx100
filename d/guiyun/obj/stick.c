// Obj: /d/guiyun/obj/stick.c
// Last Modified by winder on Jul. 9 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��֦", ({ "shuzhi", "stick" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ͨ��С��֦����������£��о������������̵��ˡ�\n");
		set("value", 1);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N���������е�$n��\n");
	}
	init_sword(2);
	setup();
}
