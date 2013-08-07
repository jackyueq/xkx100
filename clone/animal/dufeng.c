// dufeng.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("����", ({ "dufeng", "feng" }) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 5);
	set("long", "����һֻ���䣬������Ϯ����\n");
	set("str", 50);
	set("dex", 60);

	set("limbs", ({ "ͷ��", "����", "���", "β��" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 30);

	setup();
}

void unconcious()
{
	object ob;

	if( base_name(environment(this_object())) == "/d/dali/chhill4" &&
		random(6) > 0 )
	{
		ob = new(__FILE__);
		 ob->move(environment());
		 message_vision("\n�ˣ��ˣ��ˣ��ַ���һֻ���䡣\n", this_object());
	} else {
		 message_vision("\nһ�������䴵���ˡ�\n", this_object());
	}

	destruct(this_object());
}

void die()
{
	object ob;

	if( base_name(environment(this_object())) == "/d/dali/chhill4" && random(6) > 0 ) {
		 ob = new(__FILE__);
		 ob->move(environment());
		 message_vision("\n�ˣ��ˣ��ˣ��ַ���һֻ���䡣\n", this_object());
	} else {
		 message_vision("\nһ�������䴵���ˡ�\n", this_object());
	}

	destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("insect_poison", 3 + random(3) +
		victim->query_condition("insect_poison"));
}
