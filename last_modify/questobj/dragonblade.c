// dragonblade.c ������

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(BLU"������"NOR, ({ "dragon_blade", "blade", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "�˵��ɹ������ط򸾴��죬�����������\n");
		set("material", "steel");
                set("value",0);
		set("wield_msg", HIB "�ͼ��ڹ�һ����������Ծ��$N���С�˲ʱ��ؼ�������\nһƬ�ڰ���ɱ���С�\n" NOR);
		set("unwield_msg", HIB "$N���е�����������ؼ����ɱ֮������ɢȥ��\n" NOR);
	}
	setup();
}

