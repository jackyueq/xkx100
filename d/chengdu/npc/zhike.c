// Room: /d/chengdu/npc/zhike.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("֪��ɮ", ({ "zhike seng", "zhike", "seng" }));
	set("long", "�����Ѿ��µ�֪�ͺ��У������Ȼ���󣬵������������µĿ̺ۡ�\n");
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 22);
	set("int", 24);
	set("con", 26);
	set("dex", 21);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 6000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);

	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
	carry_object(CLOTH_DIR"seng-shoe")->wear();
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
	switch( random(2) )
	{
		case 0:
			say( "֪��ɮ˫�ֺ�ʲ˵������λʩ�����������㣿\n");
			break;
		case 1:
			say( "֪��ɮ�������Լ��Ĺ�ͷ��˵������λ" + RANK_D->query_respect(ob) + "����������\n");
			break;
	}
}

