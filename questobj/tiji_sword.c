// tiji_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIB"��"HIM"��"NOR, ({ "xingyu sword", "lqy", "sword" }));
	set_weight(6000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N������һ���������һ��$n�������С�\n");
		set("unwield_msg", "$N����$nӭ��һ����գ�ۼ���Ȼ����Ӱ�١�\n");
	}
	setup();
}


