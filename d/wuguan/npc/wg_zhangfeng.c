// wg_zongguan.c ����ܹ�

#include <ansi.h>

inherit NPC;
string *names = ({"��ɨ��","��ľͷ","����","���˵�","����","��ˮ",});
string ask_job();

void create()
{
	set_name("�ŷ�", ({ "zhang feng","zhang","feng", "zongguan" }));
	set("title", "��������ܹ�");
	set("gender", "����");
	set("age", 45);
	set("str", 27);
	set("dex", 26);
	set("int", 20);
	set("con", 20);
	set("per", 16);
	set("long", "������ò�Ͱ���Ц�Ǻǵģ�һ���ø����̴���\n");
	set("combat_exp", 700000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set_skill("unarmed", 120);
	set_skill("force", 130);
	set_skill("strike", 160);
	set_skill("hammer", 100);
	set_skill("kunlun-strike", 160);
	set_skill("xuantian-wuji", 160);
	set_skill("kunlun-shenfa", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "kunlun-strike");
	map_skill("force", "xuantian-wuji");
	map_skill("strike", "kunlun-strike");
	prepare_skill("strike","kunlun-strike");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
	set("inquiry", ([
		"����" : (: ask_job :),
		"job" : (: ask_job :),
		"����" : "��ȥ��Ʒ��������Ҫ�ɣ�",
	]));
	setup();
	carry_object("clone/cloth/cloth")->wear();

}

void init()
{
	object ob;
	::init();

	if (interactive(ob = this_player()) && !is_fighting() && !wizardp(ob))
	{
		if((int)ob->query("combat_exp") > 100000) return;
		else
		{
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}
	add_action("do_job","job");
}
string ask_job()
{
	object me, ob;
	string target;
	ob=this_player();
	me=this_object();

	target = names[random(sizeof(names))];
	if (ob->query_temp("job_name"))
		return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
	if (ob->query("combat_exp") >= 100000)
		return ("�㹦���Ѿ��㹻��������������û��ʲô�ʺ���Ĺ����ˡ�\n");
	ob->set_temp("job_name",target);
	ob->apply_condition("wuguan_job",random(3)+4);
	return "���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժ"+ target+ "�ɡ�";
}
int do_job(string arg)
{
	int add_exp,add_pot,exp,pot;
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!arg || arg!="ok") return 0;

	if(!ob->query_temp("job_name"))
		return notify_fail("û���㹤��������ô���������ˣ�\n");
	if (interactive(ob) && (int)ob->query_condition("wuguan_job"))
	{
		command("hmm "+ob->query("id"));
		return notify_fail(RED "����ô������ˣ��ǲ��ǻ�û���갡���Ը����������"NOR);
	}
	if(!ob->query_temp("mark/����"))
		return notify_fail("���Ȱѹ��߻������������������ɡ�\n");

	if(!(ob->query_temp("mark/������") || 
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/������") ||
		ob->query_temp("mark/ɨ����") ||
		ob->query_temp("mark/������")))
		return notify_fail("��͵����������ɻ��㲻ȥ�ɣ������칦��\n");

	command("smile "+ob->query("id"));
	command("say �ã�"+RANK_D->query_respect(ob)+"�����úã����Ǹ���Ľ��ͣ�");
	if (random(10)<7)
	{
		me->add_money("coin",(int)(ob->query_skill("force",1)/2)+65);
		command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/2)+50)+" coin");
	}
	else
	{
		me->add_money("silver",(int)(ob->query_skill("force",1)/5)+1);
		command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/5)+1)+" silver");
	}
	add_pot=50 + random(50) + (int)(ob->query_skill("force",1)/10);
	add_exp=100 + random(100) + (int)(ob->query_skill("force",1)/5) ;	
	exp=(int)ob->query("combat_exp");
	pot=(int)ob->query("potential");
	exp= exp + add_exp;
	pot= pot + add_pot;
	ob->set("combat_exp",exp);
	ob->set("potential",pot);
	tell_object(ob,HIW"��õ���:"
		+ chinese_number(add_exp) + "��ʵս���飬"
		+ chinese_number(add_pot) + "��Ǳ�ܣ�\n"NOR);
	ob->delete_temp("job_name");
	ob->delete_temp("mark");
	ob->set_temp("prize_reason","���");
	ob->set_temp("can_give_prize",1);
	ob->set_temp("prize_exp",add_exp);
	ob->set_temp("prize_pot",add_pot);
	return 1;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ||
		ob->query_temp("job_name") || ob->query("combat_exp") > 1000 )
		return;

	command("bow "+ob->query("id"));
	command("say ��λ"+RANK_D->query_respect(ob)+"��������ȱ���֣�����������칤��������\n");
}

