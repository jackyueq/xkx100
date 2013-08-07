// baidu5.c
inherit NPC;
#include <ansi.h>

string *first_name = ({"�嶾", "����", "���", "����"});
string *name_words = ({"���"});

void create()
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];

	set_name(name,({"chan chu"}));
	set("race", "Ұ��");
	set("long", "һֻȭͷ��С����ͷ���Ե�С��󡡣\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 200);
	set("max_qi", 200);

	set("str", 20);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	set("combat_exp", 10000);
	set_weight(500000);

	setup();
}
void init()
{
	object me,ob;
	add_action("do_train", "xun");
	if (interactive(me = this_player()) && 
	    (string)me->query("family/family_name") != "�嶾��")
	{
		if (!(ob = present("xionghuang", this_player())))
		{
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me);
		}
	}
	::init();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "�嶾��") {
		ob->apply_condition("chanchu_poison", 20
	      +(int)ob->query_condition("chanchu_poison") );
	      tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
       }
}
#include "baidu.h";
