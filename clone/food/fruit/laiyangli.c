// laiyangli.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(HIY"������"NOR, ({"laiyang li","li","pear"}));
	set_weight(4000);
	set("long", "һ�����Ĵ������Ƴγε���������Ѽ�档\n");
	set("unit", "��");
	set("life", 7);
	set("value", 0);
	set("fruit_remaining", 2); //���Գ�5��
	set("food_supply", 15);   //ÿ�ڼ�5��food
	set("water_supply", 25);  //ÿ�ڿ��Լ�15��water
	set("eat_msg", "$N����$n�����Ŀ���һ�ڡ�\n");
	set("end_msg", "$N��ϸ�Ŀ��������$n��\n");
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n");
	set("core", "���");	 //name
	set("core_id", ({"li hu", "pear core", "hu", "core"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ���еøɸɾ�������ˡ�\n"); //long
	set("gifts", ([
		"per" : 2,
		"int" : 2,
		"con" : -1,
	]));
	setup();
}
