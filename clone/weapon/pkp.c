// pkp.c �˿���

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�˿���", ({ "pkp" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ���˿��ƣ�һ��Ķ�ͽ��ʹ������\n");
		set("value", 100);
		set("material", "paper");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Żؿڴ���\n");
	}
	init_sword(25);
	setup();
}
