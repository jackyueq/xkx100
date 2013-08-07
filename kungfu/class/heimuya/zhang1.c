// zhang1.c
#include <ansi.h>
inherit NPC;

int shang_ya();
void create()
{
	set_name("�ų˷�", ({"zhang chengfeng", "zhang", "chengfeng"}));
	set("nickname", HIY "�����ħ" NOR );
	set("gender", "����");
	set("age", 42);
	set("shen_type", -1);
	set("long", "�����������ǰ�����ϡ�\n");
	set("attitude", "peaceful");
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);

	set("combat_exp", 1500000);
	set("score", 0);
	set("inquiry", ([
		"��ľ��"   : "��ľ�µ��ӻ�ֽ������Ʒ��ܡ����¡���\n",
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"��ľ��"   : "���Ǳ��̽������ƣ���������������٣�\n",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
		"����"     : (: shang_ya :),
	]) );

	set_skill("force", 150);
	set_skill("kuihua-xinfa", 150);
	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("dodge", 150);
	set_skill("lingxu-bu", 150);
	set_skill("parry", 150);
	set_skill("club", 150);
	set_skill("weituo-gun", 150);

	map_skill("force", "kuihua-xinfa");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu-bu");

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIR"ǰ������"NOR);
	create_family("��ľ��", 4, "����");

	setup();
	carry_object("/d/heimuya/npc/obj/shutonggun")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int shang_ya()
{
	object ob, myenv ;
	ob = this_player ( ) ;
	if (ob->query("family/family_name") == "��ľ��")
	{
		message_vision("�ų˷�һ���֣���������һ���������\n",ob);
		message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n",ob);
		myenv = environment (ob) ;
		ob->move ("/d/heimuya/basket");
		call_out("goto_heimuya", 10, ob) ;
	   	return 1;
	}
	else  
		message_vision("�ų˷��������´�����$Nһ�£�ʲô�����£���ĺ�ľ���أ���\n",ob);
	return 1;
}

int accept_object(object who, object ob)
{
	object myenv ;
	if (ob->query("id") == "heimu ling")
	{
		message_vision("�ų˷��$N˵���ã���λ" + RANK_D->query_respect(who) + "�����Ǿ���ɣ�\n" , who);
		message_vision("�ų˷�һ���֣���������һ���������\n", who);
		message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n", who);
		myenv = environment (who) ;
		who->move ("/d/heimuya/basket");
		call_out("goto_heimuya",10,who) ;
	   	return 1;
	}
	else  
	{
		message_vision("�ų˷��$N˵�����ˣ�ң���\n", who);
		this_object()->kill_ob(who);
	}
	return 0;
}

void goto_heimuya (object ob)
{
	tell_object(ob , "����ǰһ����һ������ɫ����������ǰ�����ǻԻ͡�\n");
	ob->move ("/d/heimuya/chengdedian") ;
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ��յ��ӡ�\n");
	return;
}

