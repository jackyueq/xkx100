// shiliu.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(HIR"ʯ��"NOR, ({"shi liu", "shiliu","pomegranate"}));
	set_weight(4000);
	set("long", "һ���ѿ��˿ڵı�Ƥ��ʯ��\n");
	set("unit", "��");
	set("life", 30);
	set("value", 0);
	set("fruit_remaining", 5); //���Գ�5��
	set("food_supply", 5);   //ÿ�ڼ�5��food
	set("water_supply", 25);  //ÿ�ڿ��Լ�5��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n�����˼����Ѷ�����ȥ��\n");
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N��ϸ�İ�����󼸸��ѳ���ȥ��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	// ˮ������ʣ�µĶ��� :-)
	set("core", "ʯ��Ƥ");	 //name
	set("core_id", ({"shiliu pi", "pomegranate peel", "pi", "peel"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ��ʯ��Ƥ��\n"); //long
	set("gifts", ([
		"per" : 1,
		"cps" : 1,
	]));
	setup();
}

