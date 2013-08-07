// Last Modified by winder on Apr. 25 2001
// pi2.c �Խ� ��������
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�Խ�", ({ "pi jiang", "pi", "jiang" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "����һ���������Ὣ�죬����������\n");
	set("combat_exp", 45000);
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
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
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
	if(ob->query_temp("guosc_mis_flag")==2)
	{
		say("�Խ�������ü����λ" + RANK_D->query_respect(ob) + "���㻹�ǰ����سǰɡ�\n");
	}	
	else if(ob->query_temp("guosc_mis_flag")==1)
	{
		say("�Խ�����˵������λ" + RANK_D->query_respect(ob) + "������������ʱ���ɹ������Ѿ��칥�ϳ��ˡ�\n");
	}
	if(ob->query_temp("guosc_mis_flag")==3)
	{
		say("�Խ�����˵������λ" + RANK_D->query_respect(ob) + "�����Ѿ����Ի�ȥ�����ˡ�\n");
		return;
	}
}
