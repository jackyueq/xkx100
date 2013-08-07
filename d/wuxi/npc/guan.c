// guan.c �佫

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("�̽���", ({ "cai jinyi", "cai", "jinyi" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "
��������Ц��������˻����������Χ������˵���������ֺô�������ʱ�س�
���Լ�ո�µľ���������΢΢����Ķ�Ƥ��Ҫ��ξ��Ļ���ȥ�����ɣ�\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	tell_object(ob,"�̽������ҿ��˿���˵������λ"+RANK_D->query_respect(ob)+"��Ҫ�뵱���͸Ͽ챨�����Ҹ����������\n");

	return;
}
