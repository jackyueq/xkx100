// Last Modified by winder on Feb. 28 2001
// yangguo.c ���

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("���", ({"yang guo", "yang", "guo"}));
	set("nickname", HIB"������"NOR);
	set("gender", "����");
	set("age", 26);
	set("long",
	"�����������������һ����񳿡������ף���ü���ޣ�����������\n"
	"��Ȼ��ֻ��һֻ�첲�����ǿ�ΰ����������˸о�Ӣ�����ˡ�\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("chat_chance", 1);
	set("chat_msg", ({
		"���̾�˿�����������֪�������ڿɺã�ʮ�����ˣ���һֱ�������\n", 
		"����૵�����������ܣ�������ܣ���һ�ܶ����ɵã���\n", 
	}));
	set("chat_chance_combat",50);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.anran" :),
		(: command("wield jian") :),
		(: command("unwield jian") :),
	}));

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("yunv-xinfa", 200);
	set_skill("sword", 200);
	set_skill("yunv-jian", 200);
	set_skill("quanzhen-jian",200);
	set_skill("dodge", 200);
	set_skill("anran-zhang",220);
	set_skill("yunv-shenfa", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("meinv-quan", 200);
	set_skill("literate",120);
	set_skill("qufeng",120);
	set_skill("tanzhi-shentong",200);
	set_skill("iron-sword",200);
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "iron-sword");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "anran-zhang");

	create_family("��Ĺ��", 4, "����");
	set("letter_count", 1);

	set("inquiry", ([
		"����"     :(: ask_me :),
		"С��Ů"   :"��֪�������������䣿\n",
		"��Ů����" :"��Ů������ȫ�潣���ϱڣ������޵У�\n",
		"��Ĺ��"   :"�ҵ�����ʦүү������������ʦ��һ����ˣ�����...\n",
		"����"     :"�ҹ������ǵ���һ��������\n",
		"����"     :"�ҹ���ĸȷʵ�������Ųߡ�\n",
		"����"     :"���ּ�����ʦ���ิ���ѡ�\n",
		"���"     :"���ʵ��֣�\n",
		"������"   :"�������ڶ��½�ڣ��\n",
		"���½�ڣ" :"���½�ڣ��Լ��Ұɡ�\n",
	]) );
	set("env/wimpy", 40);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] != "��Ĺ��") return;
	if ((int)ob->query_temp("marks/С��Ů") == 1 )
	{
		if (ob->query_int() < 40)
		{
			message_vision("������˿�$N˵�������㱿ͷ���Եģ�������ȥ������ɡ�\n", ob);
			return;
		}
		if (ob->query_skill("yunv-xinfa",1) < 150)
		{
			message_vision("������˿�$N˵������ı����ķ����������Ŭ��һ�Ѱɡ�\n", ob);
			return;
		}
		if (ob->query_skill("yunv-jian",1) < 150)
		{
			message_vision("������˿�$N˵������ı��Ž������������Ŭ��һ�Ѱɡ�\n", ob);
			return;
		}
		if (ob->query_skill("quanzhen-jian",1) < 150)
		{
			message_vision("������˿�$N˵�������ȫ�潣�����������Ŭ��һ�Ѱɡ�\n", ob);
			return;
		}
//message_vision("���̾�˿���������$N��˵������û�ҵ��ҵ�����ô��\n", ob);
		command("say �ðɣ��Ҿ����������ͽ���ˡ�\n");
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("���̾�˿���������$N��˵������û�ҵ��ҵ�����ô��\n", ob);
		return;
	}
}

int accept_object(object me, object ob)
{
	object obn;
	if ( (string) ob->query("id") =="junzi jian" )
	{
		message_vision("���˵������λ"+ RANK_D->query_respect(me)+"����ʵ�ڸ���������ҵ���������������ں���\n",me);
		if(query("letter_count") > 0)
		{
			message_vision("����ֶ�$N˵�����鷳����Ұ��Ž��������������ҵ�������ʮ�����ˣ������������\n" , me);
			obn=new("/d/gumu/npc/obj/letter");
			obn->move(me);
			add("letter_count", -1);
		}
		return 1;
	}
	return 0;
}

string ask_me()
{
	object me=this_player();
	if(present("junzi jian",this_object()))
		return "��л��Ĺ����������Ѿ�����������Ϣ�ˡ�\n";
	else
	{
		me->set_temp("mark/��",1);
		return "������������Ϣ��\n";
	}	
}

