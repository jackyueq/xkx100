// xianglu.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("��¯", ({ "xiang lu", "lu" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�������µ���¯��¯��Ʈ�����󵭵�̴�㡣\n");
		set("value", 100);
		set("material", "gold");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
}

