// animal: snake.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
int snake_attspeed(object);

void create()
{
	set_name("����", ({ "snake", "fushe" }) );
	set("race", "����");
	set("age", 10);
	set("long", "һ�����δ�׳�ĸ��ߣ��涾�ޱȡ�\n");
	set("attitude", "peaceful");

	set("str", 33);
	set("cor", 33);
	set("combat_exp", 20000 + random(20000));

	set_temp("apply/attack", 50 + random(20));
	set_temp("apply/damage", 20 + random(10));
	set_temp("apply/dodge", 20 + random(10));
	set_temp("apply/armor", 20 + random(10));

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 80 +
		victim->query_condition("snake_poison"));
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
	ob = new("/d/shenlong/obj/shedan");
	ob->move(environment(this_object()));
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}