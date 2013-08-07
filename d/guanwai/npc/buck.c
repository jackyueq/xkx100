// buck.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name(YEL"÷����¹"NOR, ({ "meihua xionglu", "buck", "lu" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 20);
	set("long", "һֻ��ѱ��÷����¹�����ڵ�ͷ�Բݡ�\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("combat_exp", 2000);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 10);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N��������İ������������ڵ��ϣ���ȥ�ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/lurong");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
