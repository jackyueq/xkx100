// murong.c
inherit ITEM;

void create()
{
	set_name("ľͰ", ({ "mu tong" }));
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ������ľͰ��\n");
		set("unit", "ֻ");
		set("value", 0);
	}
}

