// qingcai-fentiao.c ��˷���
// Last Modified by Sir on May. 22 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"qingcai fentiao","fentiao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������䣬����ɿڵ���˷�����\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
