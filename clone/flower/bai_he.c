// bai_he.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit COMBINED_ITEM;
int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIC "�ٺ�" NOR, ({"bai he", "bai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ����Ź°��İٺϻ��������۾�������񣬰�������\n�ɶ�����ʮ���ص�������һ�𣬺����Ƭ�ϳɣ������š���\n��úϣ����º��ġ�֮�⡣\n");
		set("unit", "��");
		set("value", 45);
		set("base_unit", "��");
		set("base_weight", 100);
		set("flower", 1);
	}
	set_amount(1);
}
#include "flower.h"
