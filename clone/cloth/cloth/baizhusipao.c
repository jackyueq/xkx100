// baizhusipao.c ����˿��

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("����˿��", ({ "baisi pao", "cloth" }));
	set("long","һ����ɫ����˿�ۣ��ü����壬���ƾ�ϸ��\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 1000);
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 2);
	}
	setup();
}

