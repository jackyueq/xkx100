// biyuqiang.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("����˫ǹ", ({ "jade spear", "spear" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ�����Ƶ���ɫ��ǹ��������Ǯ�˼ҵİ��裬ȴ�ַ����ޱȣ�\n");
		set("value", 9000);
		set("material", "blacksteel");
		set("wield_msg","$N˫��һ�֣��ӱ������һ�Զ�ǹ�յ����У�\n");
		set("unwield_msg", "$N�����е�$nϵ������\n");
	}
	init_spear(20);
	setup();
}

