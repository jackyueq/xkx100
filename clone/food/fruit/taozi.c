// taozi.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(HIM"����"NOR, ({"tao zi", "taozi","peach"}));
	set_weight(4000);
	set("long", "һ������������Ц�Ĵ����ҡ�\n");
	set("unit", "��");
	set("life", 5);
	set("value", 0);
	set("fruit_remaining", 2); //���Գ�6��
	set("food_supply", 10);   //ÿ�ڼ�10��food
	set("water_supply", 30);  //ÿ�ڿ��Լ�10��water
	set("eat_msg", "$N����$n�����Ŀ���һ�ڡ�\n"); 
	set("end_msg", "$N��ϸ�Ŀ��������$n��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("core", "�Һ�");	 //name
	set("core_id", ({"tao hu", "peach core", "core", "hu"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ���еøɸɾ������Һˡ�\n"); //long
	set("gifts", ([
		"per" : 1,
		"int" : 1,
	]));
	setup();
}

