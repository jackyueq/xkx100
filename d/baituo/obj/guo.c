inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("Ұƻ��", ({"ye pingguo","pingguo", "guo" }));
	set_weight(25);
	if (clonep())
	set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ��Ұ����������ƻ����\n");
		set("food_remaining", 1);
		set("food_supply", 30); 
		setup();
	}
}
