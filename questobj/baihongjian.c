// baihongjian.c �׺罣

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"��"HIM"��"HIG"��"NOR,({ "baihongjian", "sword", "jian" }));
	set_weight(8000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����������ı�����\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ������������$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	setup();
}
