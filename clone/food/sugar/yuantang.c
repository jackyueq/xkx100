// yuantang.c

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(MAG"ԧ����"NOR, ({"yuanyang tang","tang"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ӨԲ���͸���ǿ顣\n");
		set("unit", "��");
		set("value", 20);//�ܱ��ˣ�������ʳ�ﶼӦ�úܱ��ˣ�.
		set("food_remaining", 3);
		set("food_supply", 10);//������������һ�ٳԶ��
	}
}
