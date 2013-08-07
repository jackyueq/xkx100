//jinshe.c

#include "ansi.h"
inherit NPC;

void create()
{
	set_name("��˹����", ({ "pusi qushe", "she", "qushe" }) );
	set("race", "����");
	set("age", 2);
	set("long", @LONG
�ⶾ�������������Ž�⣬ͷ��������ǣ���״ʮ�ֹ��졣
LONG
);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);

	set("combat_exp", 15000+random(10000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 40) 
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

void die()
{
	object ob;
	message_vision("$N��˻˻���ؽ��˼������ϳ����أ����ˣ�\n", this_object());
	if(uptime() > 300)
	{
		ob = new("/clone/medicine/nostrum/guaishedan");
		ob->move(environment(this_object()));
	}
	destruct(this_object());
}

int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 50000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
		&& (int)ob->query_condition("snake_poison") < 10 )
	{
		ob->apply_condition("snake_poison", 20);
		tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
