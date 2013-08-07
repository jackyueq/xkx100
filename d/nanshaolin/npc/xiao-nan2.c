// Last Modified by winder on May. 29 2001
// Npc: /d/nanshaolin/npc/xiao-nan.c

inherit NPC;

void create()
{
	set_name("Сɳ��", ({ "xiao shami", "xiao", "shami"}));
	set("long", "����һλδͨ���ʵ�������У����Ϲ����������Ц��\n");

	set("nickname", "��իɮ");
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 10);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 9);
	set_skill("dodge", 9);
	set_skill("unarmed", 9);
	set_skill("parry", 9);

        create_family("��������", 23, "����");
	setup();
}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("Сɳ�ֹ���˵������λ"+RANK_D->query_respect(ob)+"����������\n");
}

void serve_food(object who)
{
	object ob;
	object room;

	if( !who || environment(who) != environment() ) return;
	if( !who->query_temp("marks/sit") ) return;
	if( !objectp(room = environment()) ) return;
 	ob = new(FOOD_DIR+"mizhi-tianou");
	ob->move(room);
	message_vision("Сɳ�ֶ���һ����֭��ź�������ϣ�\n", who);
	
	return;
}

