// /kungfu/class/mingjiao/zhangwuji.c
// Last Modified by winder on Oct. 30 2001

#include <ansi.h>;
inherit F_MASTER;
inherit F_MANAGER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
	object ob;
	seteuid(getuid());
	set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));
	set("long", "���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�\n"
		+"�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������\n"
		+"����Ӣ�ۡ�\n");
	set("gender", "����");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "friendly");
	set("class", "fighter");

	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3050);
	set("max_qi", 3050);
	set("jing", 3050);
	set("max_jing", 3050);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 150);

	set("combat_exp", 3000000);
	set("score", 455000);
	
	set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("claw", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword",200);
	set_skill("blade", 200);
	set_skill("jiuyang-shengong", 200);
	set_skill("qiankun-danuoyi", 250);
	set_skill("sougu", 200);
	set_skill("hanbing-mianzhang", 200);
	set_skill("qishang-quan", 200);
	set_skill("lieyan-dao", 300);
	set_skill("liehuo-jian", 300);
	set_skill("shenghuo-ling", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("sword","shenghuo-ling");
	map_skill("parry","shenghuo-ling");
	map_skill("claw", "sougu");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("cuff", "qishang-quan");
	map_skill("blade", "lieyan-dao");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	prepare_skill("cuff", "qishang-quan");

	set("party/party_name",HIG"����"NOR);
	set("party/rank",HIM"����"NOR);
	create_family("����", 34, "����");

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.tougu" :),
		(: perform_action, "sword.yinfeng" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	set("chat_chance",2);
	set("chat_msg",({
"���޼ɷ�Ȼ˵���������ɷ��Թ�Ϊ�ң�����ɳ������Ԫ��ҵδ�ɣ�ͬ������Ŭ������\n",
"���޼�̾����������ʧһ֪��������λ���������ǣ����������������\n",
"���޼ɵ������ҽ��ֵ����ˣ��������������˼�Ϊ�����������壬������ħ����\n",
	}));

	set("inquiry",([
		"��ëʨ��":"�������常л������ְ˾��\n",
		"лѷ"  :"���������常�Ĵ�š�\n",
		"�Ŵ�ɽ":"�������Ҹ��������᣿\n",
		"������":"����������������΢������\n",
		"������":"��̫ʦ�������ɺã�\n",
		"����"  :"����ʧһ֪��������λ���������ǣ��������������\n",
		"С��"  :"С���ҿ�һֱ�������ĺô���\n",
		"������":"������ȥ����ɽ���������ҡ�\n",
	]));
	setup();
	if (clonep())
	{
    ob=new(WEAPON_DIR"treasure/yitian-jian");
    if (ob->violate_unique())
      destruct(ob);
    else
      ob->move(this_object());
	}
	carry_object("/clone/book/shenghuo-ling")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();
	add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
      
        add_action("do_qiecuo","qiecuo");
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
		command("wield shenghuo ling");
		command("hit"+(string)ob->query("id"));
		command("unwield shenghuo ling");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say ħ����������ѧ������������Ȱ���������������سɷ�");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say ��λ���ѣ����н��������е����������߽�аħ�����");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say �������������ߣ�Ȱ����ӱ��ء�");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say �������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳���");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say �������̫���ˣ����ʺ�ѧϰ�ҵĹ���");
		return 0;
	}
	if((string)ob->query("gender")=="����")
	{
		command("say ���������㣬ϰ�ҹ���ֽ��߻���ħ��");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say ��Ӧ������Щ����������£��������ġ�");
		return 0;
	}
	command("say �ã��Ҿ���������λ��ͽ�ܣ�");
	command("recruit " + ob->query("id"));
	return;
}

int accept_fight(object ob)
{
	if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
	{
		message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣���ȥ�ɡ�\n",ob);
		return 0;
	}
	message_vision("���޼�һ����˵������λ"+RANK_D->query_respect(ob)+
	"����������ˡ�\n", ob);
	return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
			command("say ���ְ˾���Ǳ��̵Ĺ���ʹ�ߡ�");
			ob->set("title", HIR"����ʹ��"NOR);
 				  }
}
