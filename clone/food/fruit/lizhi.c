// lizhi.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(RED"��֦"NOR, ({"li zhi", "lizhi", "litchi"}));
	set_weight(4000);
	set("long", "һ�������޵���֦��\n");
	set("unit", "��");
	set("life", 3);
	set("value", 0);
	set("fruit_remaining", 5); 
	set("food_supply", 10);   
	set("water_supply", 40);  
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������Ƥ�������ﶪ��һ�ţ����ۡ����³��ˡ�\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N�Թ������һ��$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"per" : 1,
		"int" : 1,
		"spi" : 1,
	]));
	setup();
}

