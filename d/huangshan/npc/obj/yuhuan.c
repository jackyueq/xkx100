// yuhuan.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name( HIG "�񻷵�" NOR, ({ "yuhuan dao", "yuhuan", "blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ͨ�����ɫ�ĵ���");
		set("value", 400000);
		set("rigidity", 200);
		set("material", "steel");
	}
	init_blade(40);
	set("wield_msg", "$N�ӵ����г��һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��ص����С�\n");
	setup();
}

