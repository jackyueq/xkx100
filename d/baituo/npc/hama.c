// hama.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("���", ({ "chan chu", "chu", "hama" }) );
	set("race", "Ұ��");
	set("age", 10);
	set("long", "һֻ�ʴ����ܣ�ſ�ڵ���һ��������\n");
	set("attitude", "peaceful");	
	set("limbs", ({ "ͷ��", "����", "��֫", "��Ƥ" }) );
	set("verbs", ({ "hoof"}) );
	set("combat_exp", 1900);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 8);
	set_temp("apply/armor", 8);
	setup();
}

void init()
{
	object ob = this_player();
	::init();
	if (interactive(ob) && !ob->query_skill("hamagong", 1))
	{
		this_object()->kill_ob(this_player());
	}
}
int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + 3);
	return 0;
}
