// purple2.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit COMBINED_ITEM;
int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(MAG "�����" NOR, ({"gejin zi", "mudan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"����һ��Ӻ�ݻ������ɫĵ������������ȶ��ˣ�ίʵ�����������ԡ�\n"NOR);
		set("unit", "��");
		set("value", 100);
		set("base_unit", "��");
		set("base_weight", 100);
		set("flower",1);
	}
	set_amount(1);
}
#include "/clone/flower/flower.h"
