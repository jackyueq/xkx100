// shayu.c
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("����", ({ "sha yu", "sha" }) );
	set("race", "����");
        set("age", 20);
        set("long", "һֻ�����ڱ����ľ޴��衣\n");
        set("attitude", "friendly");
        set("shen_type", 0);

        set("combat_exp", 100000);
        set_temp("apply/attack", 800);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 100);

        setup();
}


void die()
{
	object ob, corpse;
	message_vision("$Nȫ��һ����ҵ�Ť�������ڰ��������������������ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/shadan");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
