// wolfdog.c

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
	,		"���ǹ�ͻȻ������������,����������Ұ��Ӱ�:P\n"		
}) );
	set("accept_baozi",0);		
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
		(random(ob->query_kar() + ob->query_per()) < 30)
		 && !query("accept_baozi")) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
void die()
{
	object ob;
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
int accept_object(object who, object ob)
{
	if( ob->id("baozi") && !ob->is_character()) {
//?		destruct(ob);
		add("accept_baozi",1);
		command("halt");
		this_object()->remove_all_killer();
		this_object()->remove_all_enemy();
		if (query("accept_baozi")>2) {
		set_leader(who);
	  	message("vision", name() + "����Ľű߰��������ģ����ֶ����ԡ�\n", environment());
		}
		else message("vision", name() + "�ñ��������Ű��ӣ�һ������,���������ˡ�\n", environment());

	return 1;
	}
}

