// moye.c Īа��
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name( MAG "Īа��" NOR , ({ "moye jian", "jian", "sword" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����Ǻպ�������Īа������������͸��һ����������ϸ������ֻ��һ����ɱ֮��ɭȻ��ɢ��\n");
		set("value", 20000);
		set("material", "steel");
		set("weapon_prop/personality", 8);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ʱֻ��ԩ��Һ�������ë���Ȼ��\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʣ�һ���ӷ�ƽ�˾���������\n");
	}
	init_sword(120);
	setup();
}

