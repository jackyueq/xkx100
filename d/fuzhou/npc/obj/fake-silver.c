// fakesilver.c
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name(HIW"����"NOR, ({"silver", "ingot", "silver_money"}));
	set_weight(2500000);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�׻��������ӣ������˼��˰�����������������Ү��\n");
		set("unit", "��");
		set("material", "lead");
	}
	setup();
}

