// /d/shenlong/npc/zsnake.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
int snake_attspeed(object);

void create()
{
	set_name("��Ҷ��", ({ "snake", "zhuye qing" }) );
	set("race", "����");
	set("age", 4);
	set("long", "һֻ������̵��ߣ��Ե��ر�ϸС��\n");
	set("attitude", "peaceful");
	set("str", 26);
	set("cor", 30);

	set("combat_exp", 10000 + random(2000));
	set_temp("apply/attack", 25 + random(10));
	set_temp("apply/damage", 2 + random(4));
	set_temp("apply/armor", 2 + random(6));

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 80 +
		victim->query_condition("snake_poison"));
}

#include "snake.h"
