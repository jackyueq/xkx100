// fumo-dao.c ��ħ��
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name("��ħ��", ({ "fumo dao", "dao" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIC"����һ������ѩ���ķ�ħ�������м�������Ѫ��������������ƥ��\nӳ���������˵�������ǰ�ɴ�Ħ����Я����ԭ��һ·��֮������ħ��\n���Ƿ�����Ͻ�ħ������\n"NOR);
		set("value", 100000);
		set("material", "steel");
		set("wield_msg", HIY "ֻ�������һ������ħ�����ʷɳ�������Ծ��$N���С�\n˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n" NOR);
		set("unwield_msg", HIY "��ħ����$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
	}
	init_blade(250);
	setup();
}
