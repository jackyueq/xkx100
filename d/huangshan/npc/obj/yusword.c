// yusword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIG "�񻷽�" NOR, ({ "yuhuan jian", "yuhuan", "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѵ���ɫ�Ľ���\n");
		set("value", 200000);
		set("material", "steel");
		set("rigidity", 2000);
		set("wield_msg", "$N�ӽ����г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(40);
	setup();
}
