// /kungfu/class/xueshan/gelunbu.c  ���ײ�
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_fashi();
void create()
{
        set_name("���ײ�", ({ "gelun bu", "ge" }));
        set("long",@LONG
���ײ���ѩɽ���л���ɮ����ͷ�졣ͬʱ���µ��Ӵ����书��
����һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("nickname", HIG "ɮ��ͷ��" NOR);
        set("gender", "����");
        set("age", 30);
        set("no_get", 1);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 100000);
        set("score", 40000);

        set_skill("lamaism", 40);
        set_skill("literate", 30);
        set_skill("force", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("dodge", 75);
        set_skill("shenkong-xing", 100);
        set_skill("parry", 60);
        set_skill("staff", 80);
        set_skill("xiangmo-chu", 120 );
        set_skill("unarmed", 60);
        set_skill("yujiamu-quan", 90);
        set_skill("sword", 60);
        set_skill("mingwang-jian", 90);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword","mingwang-jian");
        map_skill("unarmed","yujiamu-quan");
	set("inquiry", ([
		"׼������" : (: ask_fashi :),
		"����" : (: ask_fashi :),
	]));
	
        set("env/wimpy", 60);
        
        create_family("ѩɽ��", 5, "����");
        set("class", "lama");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",100);
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
	int bonus, exp_bonus;
//	if( !ob || environment(ob) != environment() ) return;
//	if( environment(ob)->query("short") == "ѩɽ��̳" )
	if (!(int)ob->query_temp("������")) return;
	{
message_vision("���ײ�����ææ�Ը�С����������̳����񣬵����͡�\n\n", ob);
message_vision(HIR"$N��ȼ�˼�̳�е�ľ�������ͣ������һ�������\n", ob);
message_vision(HIB"һ˿����������̳��ȽȽ���𡣻�����$N�𷨸��٣��ǻ���ȥ��\n", ob);
message_vision(RED"$N����­������һ��ˮ�����ۡ���һ���͵س������ܻ����罫��ȥ��\n", ob);
message_vision(HIC"$N���ȴ�����������̣����������дǣ�������һ˿������$N��ǰ���۳��Ρ�\n", ob);
message_vision(HIG"����Խ��Խ�࣬��Ȼ�ʳ����Σ�$N��ָ���Σ��������ԣ�ָ������֮·��\n", ob);
message_vision(HIW"$N�ֳַ��壬���߱�ҡ�������ж��ܴ����䡣ͻȻ���һ��������������\n", ob);
message_vision(HIY"��Ժ���â����һ����������ָֻ���ƽ����������ϡ�\n"NOR, ob);
		if (ob->query_temp("������") > ob->query("combat_exp"))
		{
//�� ���ȶ���ľ���߹��㣬�����������档����������ң�����ʮ���ơ���
//			bonus=(ob->query_temp("������") - ob->query("combat_exp")) * ob->query_skill("lamaism",1) / 200;
			bonus= ob->query_skill("lamaism",1) / 4;
			exp_bonus= ob->query("combat_exp") * 2 * bonus /10000;
			if (exp_bonus> 2000) exp_bonus= 2000;
			if ((int)ob->query_temp("��ҷ���"))
				ob->add("combat_exp", exp_bonus);
			else 
				ob->add("combat_exp", exp_bonus / 10);
		}
		else
message_vision(HIR"\n$N��֪���������˸�����ɷ�н��µ������ȣ������ǰ�æ�ˡ�\n"NOR, ob);
		ob->delete_temp("������");
	}
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        command("say �Ҿʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));

}
string ask_fashi()
{
	mapping fam; 
	object ob = this_player();
	
	if( environment(this_object())->query("short") != "ѩɽ��ɽ��" )
		return "�������������£���û�����᣿";
	if (!(fam = ob->query("family")) || fam["family_name"] != "ѩɽ��")
		return "����������������ë�棬Ҳ������ƨ���£�";
	if ( ob->query_skill("lamaism",1) < 30)
		return "��������ķ�����ú��أ�û�����㿪̳�����¡�";
	ob->set_temp("����",1);
	return "��λ������Ҫ����λʩ��������ѽ��";
}

int accept_object(object who, object ob)
{
	object myenv ;
	if (ob->query("money_id") && ob->value() >= 100)
	{
		message_vision("���ײ�Ц�Ŷ�$N˵���ã���λ"+RANK_D->query_respect(who) + "Ҫ����������ɡ�\n", who);
		this_player()->set_temp("marks/xueshangate",1);
 	      	return 1;
	}
	if (!(int)who->query_temp("����"))
	{
		message_vision("���ײ�Ц�Ŷ�$N˵�����ֳ�����������ʲô�ã��������Լ����Űɣ�\n", who);
		return 0 ;
	}
	who->delete_temp("����");
	if (ob->query("id") == "corpse")
	{
		message_vision("���ײ�Ц�Ŷ�$N˵��������ȥ��̳�ɣ�\n", who);
		who->set_temp("������", ob->query("combat_exp"));
		if ((int)ob->query("userp"))
			who->set_temp("��ҷ���", 1);
//		who->set_leader(this_object());
//		command("go north");
//		command("go west");
//		command("go south");
		message_vision("���ײ��������뿪��\n", who);
		this_object()->move("/d/xueshan/jitan");
		return 1;
	}
	else  
		message_vision("���ײ���$N˵�����ֶ������������£�ֱ������ʡ�¡�\n", who);
	return 0;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
        if((string)ob->query("class") != "lama")       {
                ob->set("title","ѩɽ���׼ҵ���");
        }
        else    {
                ob->set("title",HIY"С����"NOR);
        }
 				  }
}