// zhen.c �廨��
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name("�廨��", ({"xiuhua zhen", "zhen", "sword"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long","һö���ִ��Ƶ��廨�룬����ȥѩ��ѩ���ġ��������˺�������Ϊ������\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N����һ���������Ѷ���һöѩ�����廨�롣\n");
		set("unwield_msg", "$N����һת��գ�ۼ��廨����Ȼ����Ӱ�١�\n");
	}
	init_sword(100);
	setup();
}
