// cow.c ���ţ

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW"���ţ"NOR, ({ "cow" }));
	set("long","һͷ���ţ��\n");
	set("race", "����");
	set("age", 5);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("ridable", "1");
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N���һ�����������ڵ��ϣ���ȥ�ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/niuhuang");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
