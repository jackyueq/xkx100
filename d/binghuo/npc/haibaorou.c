// haibaorou.c ������

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"haibao rou", "rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ѫ������۵ĺ����⡣\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}
