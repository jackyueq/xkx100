// hetao.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(YEL"����"NOR, ({"he tao", "hetao"}));
	set_weight(4000);
	set("long", "һ����Ͱ͵ĺ��ҡ�\n");
	set("unit", "��");
	set("value", 0);
	set("fruit_remaining", 8); 
	set("food_supply", 23);   
	set("water_supply", 1);  
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n��С�ĵ���������Ŀǣ����������������\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N��ʣ�µ�$n���˸��ɾ���\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"spi"  :  2,
		"int"  :  2,
	]));
	setup();
}

