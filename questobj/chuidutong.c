// chuidutong.c ����Ͳ
#include <ansi.h>
inherit ITEM;

#define max_poison 15
#define least_poison 5

void init()
{
}

void create()
{
	set_name(HIW"����Ͳ"NOR, ({ "chuidu tong", "ct" }) );
	set("taskobj", 1);
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "֧");
		set("value", 0);
		set("material", "steel");
		set("long", "����һ֧���������Ͳ����֪����ʲô�õġ�\n");
	}
	setup();
}
