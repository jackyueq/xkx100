// ganjiang-jian.c �ɽ���
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name( HIC "�ɽ���" NOR , ({ "ganjiang jian", "jian", "sword" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����Ǻպ������ĸɽ���������������͸��һ����������ϸ������ֻ��һ����ɱ֮��ɭȻ��ɢ��\n");
		set("value", 20000);
		set("material", "steel");
		set("weapon_prop/personality", 8);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ʱ��ɳ����������գ���������塣\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʣ�һ���ӷ�ƽ�˾���������\n");
	}
	init_sword(130);
	setup();
}

