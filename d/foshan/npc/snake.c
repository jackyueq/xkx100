// snake.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"��Ҷ��"NOR, ({ "zhuye qing", "snake" }) );
	set("long", "һֻ��������"HIR"����"NOR"��"HIG"��Ҷ��"NOR"����������ض����㡣\n");
	set("race", "����");
	set("age", 3);
	set("attitude", "peaceful");
	set("max_jing", 80);
	set("max_qi", 80);

	set("str", 10);
	set("cor", 50);

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	set("combat_exp", 2000);
	setup();
}

void init()
{
        object me,ob;
        ::init();
        if (interactive(me = this_player()))
        {
	if (!(ob = present("xionghuang", this_player())))          
               {
	       remove_call_out("killob");
               call_out("killob", 1, me);
		}
        }
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
void killob(object ob)
{
	if (environment(ob)==environment())
	 kill_ob(ob);
}