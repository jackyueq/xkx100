// hualu3.c
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIB"��÷��¶"NOR, ({ "hanmei hualu", "hualu" }));
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һƿ��÷��¶�������ǻ��˲�����Ѫ���Ƴɵġ�\n");
		set("unit", "ƿ");
		set("value", 0);
	}
}

