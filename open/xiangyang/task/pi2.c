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
	if(ob->query_temp("start_job")==2)
	{
		say("�Խ�������ü����λ" + RANK_D->query_respect(ob) + "���㻹�ǰ����سǰɡ�\n");
	}	
	else if(ob->query_temp("mark/job_shadi")==2)
	{
		say("�Խ�����˵������λ" + RANK_D->query_respect(ob) + "������������ʱ���ɹ������Ѿ��칥�ϳ��ˡ�\n");
		ob->apply_condition("jobshadi_limit", 5+random(5));
		ob->set_temp("start_job",2);
		ob->set_temp("where",environment(ob));
		remove_call_out("to_rob");
		call_out("to_rob",10,ob);
	}
	if(ob->query_temp("job_over")==1)
	{
		say("�Խ�����˵������λ" + RANK_D->query_respect(ob) + "�����Ѿ����Ի�ȥ�����ˡ�\n");
		return;
	}
}

void to_rob(object ob)
{
	object *target, robber, room;
	mapping my_fam = ob->query("family");
	int i;
	target = users();
	room = environment(ob);
	if(ob->query_temp("start_job")==0) return;
	if(ob->query_temp("start_job")==2)
	{
		for(i=0;i<sizeof(target);i++)
		{
			if(target[i]->query("family/family_name") == my_fam["family_name"] && target[i]->query("id")!=ob->query("id"))
			message("vission",HIR"һֻ������Ѫ�ĸ��ӷɵ�����ǰ������һ��ֽ����\n"HIW"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U          �ɹ�����������ԭ��"+room->query("short")+"�Խ���          �U\n�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a \n                              "+NOR+CYN+ob->query("family/family_name")+" "+ob->query("name")+"("+ob->query("id")+")\n" NOR,target[i]);
		}
	}
	if( environment(ob)->query("short")=="��������")
	{
		robber=new(__DIR__"robber1");
		robber->do_change(ob);
		robber->move(room);
		message_vision(HIR"ͻȻ����������һ���ɹű�ʿ��\n" NOR,ob);
		robber->kill_ob(ob);
		ob->kill_ob(robber);
	}
}

