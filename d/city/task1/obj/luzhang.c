// luzhang.c ¹����

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("¹����", ({ "luzhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ȣ���ͷ�ֲ棬��¹��֮�Σ�ͨ����ڣ���֪�Ǻ������ɡ�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_staff(50);
	setup();
}
