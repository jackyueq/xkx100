// skysword.c ���콣 
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(CYN"���콣"NOR,({"sky sword", "sword", "jian"}));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�˽��ɹ������ط򸾴��죬�����������\n");
		set("material", "steel");
		set("no_drop", "��˱���������������󰡡�\n");
		set("no_get", "���ˣ�������ĳ�����\n");
		set("no_put", "��ϧ���ɡ�\n");
		set("value",100);
		set("wield_msg", CYN "���콣�����߰�Ծ�����ʣ�����$N���У������
�貵ĺ��⣬���Ϊ֮��ɫ��\n" NOR);
		set("unwield_msg", CYN "$N���н��⽥����������Ļ����������â��\n" NOR);
       }
       init_sword(300);
       setup();
}

void owner_is_killed()
{
       destruct(this_object());
}
