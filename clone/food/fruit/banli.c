// banli.c

#include <ansi.h>
inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(HIY"����"NOR, ({"ban li", "banli"}));
	set_weight(4000);
	set("long", "һ���ʴ�İ�����\n");
	set("unit", "��");
	set("value", 0);
	set("fruit_remaining", 8);
	set("food_supply", 23);
	set("water_supply", 1);
	set("eat_msg", "$N����$n����������Ŀǣ�����س����������������\n");
	set("end_msg", "$N��ʣ�µ�$n���˸��ɾ���\n");
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n");
	set( "gifts", ([
		"con" : 1,
	]) );
	setup();
}

