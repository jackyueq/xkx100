// yougao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ǧ���͸�", ({"qianceng yougao", "yougao" }) );
	set_weight(50);//һ��
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 40);
	}
	setup();
}
