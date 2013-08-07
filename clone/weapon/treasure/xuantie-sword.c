// xuantie-sword.c ������ 
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIB "������" NOR,({"iron sword", "sword", "jian"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�˽�������������ͣ�ʮ�ֳ��أ�Ϊ���µڶ������\n");
		set("material", "steel");
		set("value", 100000);
		set("wield_msg",HIB"һ�ź����͵����������������������$N���С�\n" NOR);
		set("unwield_msg",HIB"$N����������һ�����صİ���������С�\n" NOR);
       }
       init_sword(250);
       setup();
}

void owner_is_killed()
{
       destruct(this_object());
}
