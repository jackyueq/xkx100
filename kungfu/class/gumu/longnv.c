// Last Modified by winder on Feb. 28 2001
// longnv.c С��Ů

#include <ansi.h>
inherit F_MASTER;
inherit F_MANAGER;
inherit NPC;

string ask_yunv();
string ask_me();

void create()
{
	set_name("С��Ů", ({"long nv", "long"}));
	set("gender", "Ů��");
	set("age", 18);
	set("long",
	"ӯӯ��վ��һλ�������׵�Ů�ӣ�����������һ��Ѫɫ���Եò԰��쳣��\n"
	"����һϮ��ɴ��İ��£����������������\n"
	"��������������ѩ���������֮�������䣬\n"
	"ʵ��������������¡������ݡ�\n");
	set("attitude", "friendly");

	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);

	set("chat_chance_combat", 9);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
	set("chat_chance", 1);
	set("chat_msg", ({
		"С��Ů���ĵص�������֪����������������п����Ҵ��������ϵ��֣���\n", 
		"С��Ů�૵�������Ů����ȫ�潣�ϱڣ��ǿ������޵С�����...����ȥ����һ�����أ���\n",
		"С��Ů�����̾�˿�����ת��ͷȥ��\n",
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.he" :),
	}));

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);

	set("combat_exp", 800000);
	set("score", 0);

	set_skill("force", 150);
	set_skill("yunv-xinfa", 150);    //��Ů�ķ�
	set_skill("sword", 150);
	set_skill("yunv-jian", 225);     //��Ů��
	set_skill("quanzhen-jian",220);  //ȫ�潣
	set_skill("dodge", 160);
	set_skill("yunv-shenfa", 220);   //��Ů��
	set_skill("parry", 150);
	set_skill("hubo", 120);	  //˫�ֻ���
	set_skill("unarmed",150);
	set_skill("meinv-quan", 225);    //��Ůȭ��
	set_skill("literate",120);
	set_skill("qufeng",200);	 //����֮��

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("��Ĺ��", 3, "����");

	set("book_count", 1);
	set("count",1);

	set("inquiry", ([
		"����"    : (: ask_me :),
		"���"    :  "��֪���ҹ��������䣿\n",
		"��Ů����": "��Ů������ȫ�潣���ϱڣ������޵У�\n",
		"��Ĺ��"  : "�ҵ�����ʦүү������������ʦ��һ����ˣ�����...\n",
		"��Ů�ľ�": (: ask_yunv :),
	]) );

	set("env/wimpy", 40);	
	setup();
	carry_object(__DIR__"obj/shunvjian")->wield();
	carry_object(__DIR__"obj/baipao")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
		command("say ����ʵ�ڲ��ҹ�ά������ѧ������Ů�ķ���\n");
	}
	else
	{
		command("say �ðɣ��Ҿ����������ͽ���ˡ�\n");
		command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��Ĺ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
	add("book_count", -1);
	ob = new("/clone/book/yunvjing1");
	ob->move(this_player());
	return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}

string ask_me()
{
	object ob;

	if(query("count") < 1 || this_player()->query_temp("mark/��"))
		return "��֪�����������䣿";

	add("count", -1);
	ob=new(__DIR__"obj/junzijian");
	ob->move(this_player());
	this_player()->delete_temp("mark/��");
	return "������ӽ��͸��������������������ʱ���뽻������";
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] == "��Ĺ��") return 1 ;
	if ((int)ob->query_temp("tmark/��") == 1 )
	message_vision("С��Ů̾�˿���������$N��˵�������ǵ�Ե���Ѿ����ˣ�\n��Ҳûʲô�����ɽ�����ˡ�\n", ob);
	if (!(int)ob->query_temp("tmark/��"))
		return 0;
	ob->add_temp("tmark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if ( (string) ob->query("id") =="yufeng" )
	{
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		if (!(int)who->query_temp("tmark/��"))
			who->set_temp("tmark/��",0);
		message_vision("С��Ů������䣬���ĵ�̾�˿�����˵�����ѵ��㻹�����ҵ�\n���ҵ�����ͻ���������Դ�������ѧ�㹦��\n", who);
		who->add_temp("tmark/��", 80);
		//ob->die();
		return 1;
	}
	if ( (string) ob->query("id") =="long xin" )
	{
		message_vision("С��Ů�������ţ��������棺�������������ε����ˡ�������������ȥ��\n", who);
		who->set_temp("marks/С��Ů", 1);
		set_leader(who);
		return 1;
	}
	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

