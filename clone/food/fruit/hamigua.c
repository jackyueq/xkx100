// hamigua.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(HIG"���۹�"NOR, ({"hami gua", "hamigua","cantaloup"}));
	set_weight(8000);
	set("long", "һ���к��˵Ĺ��۹ϡ�\n");
	set("unit", "��");
	set("life", 2);
//	set("value", 800);//��Ϊ�Ǵ�������˼����²��˵��ġ�
	set("fruit_remaining", 3); //���Գ�5��
	set("food_supply", 30);   //ÿ�ڼ�5��food
	set("water_supply", 70);  //ÿ�ڿ��Լ�5��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������ҧ��һ�ڣ����𰡡���\n");
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N������$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	// ˮ������ʣ�µĶ��� :-)
	set("core", "���۹�Ƥ");	 //name
	set("core_id", ({"hamigua pi", "pi", "peel"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ����۹�Ƥ��\n"); //long
	set("gifts", ([
		"int" : 1,
		"con" : 1,
	]));
	setup();
}

