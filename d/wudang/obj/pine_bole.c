// pine_bole.c �������� 
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"��������"NOR,({ "bole", "pine bole" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������ɣ����������ĺò��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("self_destruct", 1);
    	}
	setup();
}
int value()
{
	return 1;
}

