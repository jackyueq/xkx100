// huojian.c ��

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��", ({ "thick sword", "sword", "jian" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��̩ɽ���ӳ��õĵĺ񽣡�\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(30);
	setup();
}
