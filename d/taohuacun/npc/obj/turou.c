#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "����" NOR, ({"turou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ѫ�����Ұ���⡣\n");
		set("unit", "��");
	}
}
