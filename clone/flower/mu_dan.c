// mu_dan.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit COMBINED_ITEM;
int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIW "ĵ��" NOR, ({"mu dan", "mu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ��Ӻ�ݻ����ĵ������������ȶ��ˣ�ίʵ�����������ԡ�\n");
		set("unit", "��");
		set("value", 100);
		set("base_unit", "��");
		set("base_weight", 100);
		set("flower",1);
	}
	set_amount(1);
}
#include "flower.h"
