
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("������", ({ "mafang guanshi", "guanshi" }) );
	set("gender", "����" );
	set("age", 50);
	set("long",
		"����������ݵ�һ��С�ܼң�ר������Ĵ�С���£�\n");
	set("combat_exp", 55000);
	set("attitude", "friendly");
	set("inquiry", ([
		"��ɨ��" : "�����������ʵʵ���Ҵ�ɨ����û���ҵ����⣬������ȥ������",
		"��ɨ"     : "�����������ʵʵ���Ҵ�ɨ����û���ҵ����⣬������ȥ������",
	]) );
	setup();

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
	 
	if(ob->query_temp("job_name")!="��ɨ��") return; 

	if (!( present("saozhou", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say �㻹û�칤�߰ɣ�ȥ����Ʒ��������Ҫ�� \n");
		return;
	}

	if(!(ob->query_temp("job_name")!="��ɨ��"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"����������ɨ(sao ��)�ɡ�\n");
    }
}
