// dragonblade.c ������
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name(BLU"������"NOR, ({ "dragon blade", "blade", "dao" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�˵��ɹ������ط򸾴��죬�����������\n");
		set("material", "steel");
		set("no_drop", "��˱���������������󰡡�\n");
		set("no_get", "���ˣ�������ĳ�����\n");
		set("no_put", "��ϧ���ɡ�\n");
		set("value",100);
		set("wield_msg", HIB "�ͼ��ڹ�һ����������Ծ��$N���С�˲ʱ��ؼ�������\nһƬ�ڰ���ɱ���С�\n" NOR);
		set("unwield_msg", HIB "$N���е�����������ؼ����ɱ֮������ɢȥ��\n" NOR);
	}
	init_blade(300);
	setup();
}

