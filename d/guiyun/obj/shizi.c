// Obj: /d/guiyun/obj/shizi.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
#include <weapon.h>

// inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("ʯ��", ({ "shizi", "shi" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ͨͨ����ʯ�ӡ�\n");               
		set("unit", "��");
		set("value", 1);
		set("base_value", 0);
		set("base_unit", "��");
		set("base_weight", 12);
	}
	set_amount(random(70) + 81);
	init_throwing(15);
}

