
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("�񷿹���", ({ "chaifang guanshi", "guanshi" }) );
	set("gender", "����" );
	set("age", 50);
	set("long",
		"����������ݵ�һ��С�ܼң�ר�ܲ񷿣�\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("inquiry", ([
		"����" : "�����������ʵʵ�����Ҳ����⣬��ͱ����ȥ������",
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
	 
	if(ob->query_temp("job_name")!="����") return; 
	if (!( present("chaidao", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say �㻹û�칤�߰ɣ�ȥ����Ʒ��������Ҫ�� \n");
		return;
	}
	if(!(ob->query_temp("job_name")!="����"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"�������������(pi ��)�ɡ�\n");
	}
}
