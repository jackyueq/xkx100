//snake.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIG"�̾�����"NOR, ({ "ju man", "snake" }) );
	set("race", "����");
	set("age", 20);
	set("long", "һֻ��Ȼ������������������ݣ��������������԰��
����Ҫһ�ڰ������¡�\n");
	set("attitude", "aggressive");
        set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 500);
	set("max_jing", 500);
	set("str", 86);
	set("cor", 80);

	set("combat_exp", 1000000);
	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence",80);

	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
void die()
{
	object ob, corpse;
	message_vision("$Nβ��һ����֦ɨҶ���ҽ�������ͽ�͵�����ί���ڵأ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/nostrum/shedan");
	ob->move(corpse);
	corpse->move(environment(this_object()));
	destruct(this_object());
}
