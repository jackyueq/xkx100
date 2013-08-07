// animal: snake.c
// Last Modified by winder on Aug. 1 2002

// inherit NPC_TRAINEE;
inherit "/inherit/char/trainee";

void create()
{
	set_name("��Ҷ��", ({ "zhuye qing", "snake" }) );
	set("race", "����");
	set("age", 4);
	set("long", "һֻ������̵��ߣ��Ե��ر�ϸС��\n");
	set("attitude", "peaceful");

	set("msg_fail", "$n��$N˻��һ����ͷ");
	set("msg_succ", "$n˻˻���죬��ͷ����$N���ֶ�������");
	set("msg_trained","$n������Ϣ���ε�$N�Ľ��²�����");
	set("auto_follow",0);
	set("wildness", 11);

	set("str", 26);
	set("cor", 30);

	set("combat_exp", 3000);

	set_temp("apply/attack", 25);
	set_temp("apply/damage", 9);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	add_action("convert","bian");
	if (interactive(ob = this_player()) &&
	    ob->query("family/family_name") != "����ɽ" &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}
}
void die()
{
	object ob;
	ob = new(NOSTRUM_DIR"shedan");
	ob->move(environment(this_object()));
	destruct(this_object());
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 20 +
		victim->query_condition("snake_poison"));
}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="zhuye qing") return 0;
	if (me->query("family/family_name") != "����ɽ") 
		return notify_fail("�㲻�ܻ���Ϊ�ȡ�\n");
	return notify_fail("��Ҷ�����ϸС�����ܻ�Ϊ�ȡ�\n");
}

