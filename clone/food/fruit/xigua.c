// xigua.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(GRN"����"NOR, ({"xi gua", "xigua","watermelon"}));
	set_weight(8000);
	set("long", "һ���к��˵����ϣ����Ѻ�ȿ���١�����԰ɣ�\n");
	set("unit", "��");
	set("value", 0);
	set("fruit_remaining", 2); //���Գ�5��
	set("food_supply", 13);   //ÿ�ڼ�5��food
	set("water_supply", 27);  //ÿ�ڿ��Լ�5��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������ҧ��һ�ڣ�ˬ������\n");
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N������$n���������ۡ��³�һ������������\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	// ˮ������ʣ�µĶ��� :-)
	set("core", "����Ƥ");	 //name
	set("core_id", ({"xigua pi", "pi", "peel"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ������Ƥ��\n"); //long
	set("gifts", ([
		"per" : 1,
		"spi" : 1,
	]));
	setup();
}

