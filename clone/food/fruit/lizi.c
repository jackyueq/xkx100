// lizi.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(MAG"����"NOR, ({"li zi", "lizi","plum"}));
	set_weight(4000);
	set("long", "һ��Բ����Ĵ����ӡ�\n");
	set("unit", "��");
	set("value", 0);
	set("fruit_remaining", 1); //���Գ�6��
	set("food_supply", 5);   //ÿ�ڼ�10��food
	set("water_supply", 25);  //ÿ�ڿ��Լ�10��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n�����Ŀ���һ�ڡ�\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N��ϸ�Ŀ��������$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	// ˮ������ʣ�µĶ��� :-)
	set("core", "���Ӻ�");	 //name
	set("core_id", ({"lizi hu", "plum core", "core", "hu"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ���еøɸɾ��������Ӻˡ�\n"); //long
	setup();
}

