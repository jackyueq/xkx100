// xingzi.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(YEL"����"NOR, ({"xing zi", "xingzi","apricot"}));
	set_weight(4000);
	set("long", "һ���ƳγεĴ����ӡ�\n");
	set("unit", "��");
	set("life", 4);
	set("value", 0);
	set("fruit_remaining", 1); //���Գ�6��
	set("food_supply", 5);   //ÿ�ڼ�10��food
	set("water_supply", 15);  //ÿ�ڿ��Լ�10��water
	set("eat_msg", "$N����$n�����Ŀ���һ�ڡ�\n"); 
	set("end_msg", "$Nһ�ھͳԵ������$n��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("core", "�Ӻ�");	 //name
	set("core_id", ({"xing hu", "apricot core", "core", "hu"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ���еøɸɾ������Ӻˡ�\n"); //long
	set("gifts", ([
		"int" : 1,
	]));
	setup();
}

