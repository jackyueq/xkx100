// doufu.c
// Last Modifyed by Winder on Dec. 24 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���Ŷ���", ({"doufu", "dou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����ǳɶ�������С�����Ŷ����������Ŀ͹ٿɵ�С���ˡ�\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}

