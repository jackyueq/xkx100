// she.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name(HIY"��"NOR, ({ "she"}) );
	set("race", "����");
	set("gender", "����");
	set("age", 20);
	set("long", "һֻ��ѱ���꣬���ڵ�ͷ�Բݡ�\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("combat_exp", 200);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 10);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$Nͷһ�ᣬ�������ڵ��ϣ���ȥ�ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/shexiang");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
