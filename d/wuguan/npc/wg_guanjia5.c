
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��԰����", ({ "caiyuan guanshi", "guanshi" }) );
	set("gender", "����" );
	set("age", 50);
	set("long", "����������ݵ�һ��С�ܼң�ר�ܲ�԰���С���£�\n");
	set("combat_exp", 55500);
	set("attitude", "friendly");
	set("inquiry", ([
		"����" : "�����������ʵʵ���ҳ����Ӳݣ�û���ҵ����⣬������ȥ������",
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

	if (!( present("chutou", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say �㻹û�칤�߰ɣ�ȥ����Ʒ��������Ҫ�� \n");
		return;
	}

	if(!(ob->query_temp("job_name")!="����"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"������������(chu ��)�ɡ�\n");
	}
}
