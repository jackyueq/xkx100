// xianggua.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(HIG"���"NOR, ({"xiang gua", "xianggua"}));
	set_weight(4000);
	set("long", "һ������ɫ�Ĵ���ϣ�����ϲ����\n");
	set("unit", "��");
	set("value", 0);
	set("life", 15);
	set("fruit_remaining", 3); 
	set("food_supply", 6);   
	set("water_supply", 24);  
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������ҧ��һ�ڡ�\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N��ʣ�µ�$n���˸��ɾ���\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"con" : 1,
		"per" : 1,
	]));
	setup();
}

