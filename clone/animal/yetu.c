// yetu.c Ұ��
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "ye tu", "ye", "hare" }) );
	set("race", "����");
	set("age", 5);
	set("long", "һֻ�ÿɰ���СҰ�á�\n");
	set("attitude", "peaceful");
	
	set("combat_exp", 50);

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	ob = new(__DIR__"obj/turou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

