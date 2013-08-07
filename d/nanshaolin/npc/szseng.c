// Npc: /d/nanshaolin/npc/szseng.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>
string ask_job();

void create()
{
	set_name("����ɮ", ({ "shizhou seng", "shizhou","seng" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "�������Բ������������������Ͷ���\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", 
	([
		"����" : (: ask_job :),
	]));
        create_family("��������", 22, "����");
	setup();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
string ask_job()
{
	object ob = this_player();

	if (ob->query("combat_exp")>=30000)
		return ("���Ѿ����˻����ˣ�û��Ҫ������������ˡ�\n");
	if ((string)ob->query("family/family_name")!="��������")
		return ("�������ֵ��Ӳ����칤����");
	if (ob->query_temp("job_name"))
		return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
	ob->set_temp("job_name","����");
		return "��ɮ�¾�Ҫ�ܳԿ����ͣ���Ͱ��Ұ���"HIR"(ao ��)"HIC"�ɡ�";
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("job_name")!="����") return; 
	if(!(ob->query_temp("job_name")!="����"))   
	{
		command("stare "+ob->query("id"));
		command("say " + RANK_D->query_respect(ob)+"�������Ұ�æ"HIR"(ao ��)"HIC"���Ƕ�л����!!!\n");
	}
}
