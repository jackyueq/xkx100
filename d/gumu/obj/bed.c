// Room: /d/gumu/obj/bed.c ����
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"����"NOR, ({"hanyu chuang","bed","chuang"}));
	set_weight(2500000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIC"�˴�����ȥ����ͨͨ������ʯ��ȴ�ǽ�����������������������������񴲣���˵�д˴������κ������˲����л���֮Ч��С��Ů�������ܽ��ַ�����ȫ�����Ӻ���һ�������ӳ����죬�˴�������û���������Դ˴����ٳ��书���������ڹ���Ϊ��\n"NOR);
		set("no_get", 1);
		set("value", 800000);
		setup();
	}
}

