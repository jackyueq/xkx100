// luohanbai.c

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(GRN"����޺���"NOR, ({"luohan bai"}));
	set_weight(700000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ʹ��е������ľ��\n");
		set("unit", "��");
		set("no_get", 1);
	}
}

