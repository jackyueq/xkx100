// rice.c ���׷�

inherit ITEM;

void init();
inherit F_FOOD;

void create()
{
	set_name("�׷�",({"rice", "mi fan", "fan" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��մӹ���ʢ�����Ĵ��׷�����ð������������\n");
		set("unit", "��");
		set("value", 120);
		set("food_remaining", 5);
		set("food_supply", 40);
	}
}


