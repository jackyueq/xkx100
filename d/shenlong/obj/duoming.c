// duoming.c  ������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("������", ({ "duoming jian", "jian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ɵľ��ֽ��������ޱȣ�Ů�����Ƕ�ϲ������˽���\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(30);
	setup();
}
