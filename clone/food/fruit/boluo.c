// boluo.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(YEL"����"NOR, ({"bo luo","boluo","pineapple"}));
	set_weight(4000);
	set("long", "һ������Ƥ�Ĵ��ܡ�\n");
	set("unit", "��");
	set("life", 15);
	set("value", 0);
	set("fruit_remaining", 5); //���Գ�5��
	set("food_supply", 23);   //ÿ�ڼ�5��food
	set("water_supply", 70);  //ÿ�ڿ��Լ�5��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������ҧ��һ�ڡ�\n");
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N������$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	// ˮ������ʣ�µĶ��� :-)
	set("core", "���ܰѶ�");	 //name
	set("core_id", ({"boluo ba", "ba"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ�����ܰѶ���\n"); //long
	set("gifts", ([
		"per" : 1,
		"con" : 1,
	]));
	setup();
}

