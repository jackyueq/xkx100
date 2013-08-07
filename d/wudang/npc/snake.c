// animal: snake.c
// Last Modified by winder on Aug. 18 2002

inherit NPC;

void create()
{
	set_name("����", ({ "snake", "she" }) );
	set("race", "����");
	set("age", 4);
	set("long", "����һֻ�Ϸ��������û���ߣ�ϰ����һ����ߴ�Ϊ��ͬ��\n");
	set("attitude", "aggressive");

	set("str", 40);
	set("con", 30);
	set("int", 40);
	set("dex", 10);

	set("combat_exp", 1000);

	set_temp("apply/attack", 25);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 2);

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 10 +
		victim->query_condition("snake_poison"));
}

