// yu_jinxiang.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit COMBINED_ITEM;
int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIY "������" NOR, ({"yu jinxiang", "jinxiang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ����ɫ�������㣬���������������ʤ�����õ�������\n");
		set("unit", "��");
		set("value", 25);
		set("base_unit", "��");
		set("base_weight", 100);
		set("flower",1);
	}
	set_amount(1);
}
#include "flower.h"
