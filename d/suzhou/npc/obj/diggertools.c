// Last Modified by Winder on May. 15 2001
// /d/suzhou/npc/obj/diggertools.c

inherit ITEM;

void create()
{
	set_name("��Ĺ����", ({ "tools", "daomu gongju", "gravedigger tools"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ר��������Ĺ�Ĺ��ߡ��ɵ�ʱ��С�ĵ㣬����Ѳ��ץ����\n");
		set("value", 1);
		set("material", "steel");
	}
	setup();
}
