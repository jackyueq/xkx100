// luoyz_club.c
#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
	set_name(RED"�𹿰�"NOR, ({ "jingubang", "club" }));
	set_weight(6000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N������һ�����ó���һ��$n���������С�\n");
		set("unwield_msg", "$N����$n����һ��������գ�ۼ���Ȼ����Ӱ�١�\n");
	}
	setup();
}

