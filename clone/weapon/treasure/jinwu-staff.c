// jinwu-staff.c ������
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit STAFF;
inherit F_UNIQUE;

void create()
{
	set_name(YEL"������"NOR, ({ "jinwu zhang", "staff" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ѩɽ���ھ�Ӣ�����ĳ��ȡ�\n");
		set("value", 5500);
		set("material", "steel");
		set("wield_msg", "$N��������ȣ�����һȦ��ֻ����������ҫ��Ѥ����Ŀ��\n");
		set("unwield_msg", "$N���һ���������Ȳ��ڵ��ϣ��ض�ɽҡ�����ƾ��ˡ���\n");
	}
	init_staff(100);
	setup();
}

