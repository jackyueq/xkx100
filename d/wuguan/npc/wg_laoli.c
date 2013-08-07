#include <ansi.h>

inherit NPC;

int give_tools();

void create()
{
	set_name("����",({ "lao li", "li" }) );
	set("gender", "����" );
	set("age", 45);
	set("long","����������������Ʒ���ߵģ����Ƕ�ϰ�߳����������������ûʲô��֪���ˡ�\n");
	set("combat_exp", 25000);
	set("attitude", "friendly");
	set("inquiry", ([
		"����" : (: give_tools :),
	]) );
	setup();
	carry_object("clone/cloth/cloth")->wear();
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
	
int give_tools()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();

	if(ob->query_temp("mark/����"))
		return notify_fail("����˵�����Ѿ����˹����ˣ���ôû���������ˣ�");
	if(ob->query_temp("mark/����"))
		return notify_fail("����˵���㻹û�������»�ɣ�����Ҫʲô���ߡ�");

	if(!((ob->query_temp("job_name")=="��ľͷ" ) ||
		(ob->query_temp("job_name")=="����" ) ||
		(ob->query_temp("job_name")=="���˵�" ) ||
		(ob->query_temp("job_name")=="����" ) ||
		(ob->query_temp("job_name")=="��ˮ" ) ||
		(ob->query_temp("job_name")=="��ɨ��")))
		return notify_fail("����˵����û�����ܹ����ɣ�����Ҫʲô���ߡ�");
 
	if(ob->query_temp("job_name")=="����")
		tools = new((__DIR__"obj/wg_chutou"));
	else if(ob->query_temp("job_name")=="���˵�")
		tools = new((__DIR__"obj/wg_piao"));
	else if(ob->query_temp("job_name")=="��ľͷ")
		tools = new((__DIR__"obj/wg_juzi"));
	else if(ob->query_temp("job_name")=="����")
		tools = new((__DIR__"obj/wg_chaidao"));
	else if(ob->query_temp("job_name")=="��ˮ")
		tools = new((__DIR__"obj/wg_shuitong"));
	else tools = new((__DIR__"obj/wg_saozhou"));
	tools->move(this_player());
	command("say ��Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�");
	message_vision("$N����$nһ�ѹ��ߡ�\n", me, ob);
	ob->set_temp("mark/����",1);
	return 1;
}

int accept_object(object me, object obj)
{
	object ob;
	me=this_object();
	ob=this_player();

	if(!(ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/ɨ����")))
	{
		command("say �㻹û��ɹ�������ô�ͻ����������ˣ�͵����");
		return 0;
	}
	if ((obj->query("id")!="juzi") &&
		(obj->query("id")!="chutou") &&
		(obj->query("id")!="piao") &&
		(obj->query("id")!="saozhou") &&
		(obj->query("id") != "shuitong") &&
		(obj->query("id") != "chaidao"))
	{
		command("say �㻹�����˰ɣ��Ҵ�û�з����������ߡ�");
		return 0;
	}
	if(!ob->query_temp("job_name"))
	{
		command("shake");
		command("say ��û�з���������������ǲ��ǻ����ˣ�");
		return 0;
	}
	command("nod");
	command("say ��ӭ�´�������");
	ob->set_temp("mark/����",1);
	call_out("destroying", 1, me, obj);	   
	return 1;
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("mark/����")) return 0; 

	if(ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/ɨ����") ||
		ob->query_temp("mark/������"))
	{
		command("smile"+ob->query("id"));
		command("say ���������ˣ����Ի�����"HIR"(give xxx to laoli)"NOR"������! \n");
		return; 
	}
	if((ob->query_temp("job_name")=="��ľͷ" ) ||
		(ob->query_temp("job_name")=="����" ) ||
		(ob->query_temp("job_name")=="���˵�" ) ||
		(ob->query_temp("job_name")=="����" ) ||
		(ob->query_temp("job_name")=="��ˮ" ) ||
		(ob->query_temp("job_name")=="��ɨ��" ))
	{
		command("bow "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob) + "���������칤��(ask li about ����)�ɡ�\n");
	}
}				

