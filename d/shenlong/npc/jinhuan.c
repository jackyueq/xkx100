// /d/shenlong/npc/jinhuan.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
int snake_attspeed(object);

void create()
{
	set_name("����", ({ "snake", "jinhuan she","she","jinhuan" }) );
	set("race", "����");
	set("age", 8);
	set("long", "һ��ȫ�����Ž�⣬����һȦȦԲ���Ķ��ߡ�\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("cor", 30);

	set("combat_exp", 10000 + random(10000));

	set_temp("apply/attack", 10 + random(10));
	set_temp("apply/damage", 5 + random(5));
	set_temp("apply/armor", 4 + random(4));

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 60 +
		victim->query_condition("snake_poison"));
}

#include "snake.h"
