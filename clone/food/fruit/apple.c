// apple.c
#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(HIR"ƻ��"NOR, ({"ping guo","pingguo","apple"}));
	set_weight(4000);
	set("long", "һ���ִ��ֺ죬Բ�ĹĵĴ�ƻ����\n");
	set("unit", "��");
	set("life", 7);
	set("value", 0);
	set("fruit_remaining", 4); //���Գ�4��
	set("food_supply", 15);   //ÿ�ڼ�15��food
	set("water_supply", 4);  //ÿ�ڿ��Լ�4��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������ҧ��һ�ڡ�\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N�������ڳ��������$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	// ˮ������ʣ�µĶ��� :-)
	set("core", "ƻ����");	 //name
	set("core_id", ({"pingguo hu", "apple core", "hu", "core"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ��ƻ���ˡ�\n"); //long
	set("gifts", ([
		"int" : 1,
		"spi" : 1,
		"per" : 1,
	]));
	setup();
}

