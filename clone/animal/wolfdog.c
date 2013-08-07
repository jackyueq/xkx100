// wolfdog.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("���ǹ�", ({ "wolf dog", "dog" }) );
	set("race", "����");
	set("age", 4);
	set("long", "һֻ����ͦ�أ����ų���ͷ�Ĵ��ǹ������ǲ����������ĳ��\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("combat_exp", 1000);

	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"���ǹ������ͽУ�������������������������\n",
		"���ǹ�ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		!environment()->query("no_fight") &&
		random(ob->query_kar() + ob->query_per()) < 30)
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

void die()
{
	object ob;
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
