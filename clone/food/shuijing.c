// shuijing.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ˮ������", ({"shuijing baozi", "baozi" }) );
	set_weight(50);//һ��
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
	setup();
}
