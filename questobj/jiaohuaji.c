// jiaohuaji.c �л���

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�л���", ({"jiaohuaji", "ji", "chicken"}));
	set_weight(300);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����������Ľл���\n");
		set("unit", "ֻ");
		set("value", 0);
	}
}

