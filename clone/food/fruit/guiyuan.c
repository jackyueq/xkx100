// guiyuan.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(MAG"��Բ"NOR, ({"gui yuan", "guiyuan", "longan"}));
	set_weight(4000);
	set("long", "һ��Բ����Ĺ�Բ��\n");
	set("unit", "��");
	set("life", 30);
	set("value", 0);
	set("fruit_remaining", 8); 
	set("food_supply", 1);   
	set("water_supply", 4);  
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������Ƥ�������ﶪ��һ�ţ����ۡ����³��ˡ�\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N�Թ������һ��$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"int" : 2,
		"con" : 1,
	]));
	setup();
}

