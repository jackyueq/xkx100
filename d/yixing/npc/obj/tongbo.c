//Cracked by Kafei
// tongbo.c ͭ��

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ͭ��", ({ "tongbo", "bo" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ͭ�࣬����������⣬�����쳣��\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$Nȡ��һ��$n��˫�ֺϴ�������һ�������������\n");
		set("unwield_msg", "$N�����е�$n�պá�\n");
	}
	init_blade(30);
	setup();
}
