#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED "�Ǵ��Ź�" NOR, ({"tcpaigu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ɿڵ��Ǵ��Źǡ�\n");
		set("unit", "��");
		set("value", 15);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("cook_msg", "
$N��С���п�ӵ�ζ�ϰ��ȣ�������ζ���ٰ���С����ܲ���С
�ƹϹ����п顣С�����͹�ը�ɽ��ɫȡ����Ȼ����Ǭ��������
�Ͱ��ף�������м����У��ټ�����ܲ���С�ƹϡ�ը�õ�С
�ţ������ζ�ϡ�\n\n"
		);		
	}
}