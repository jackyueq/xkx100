// Last Modified by Sir on May. 22 2001
// jing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
#include <command.h>;
#include "hengshan.h";
string ask_for_join();
string ask_yao();
void create()
{
	set_name("����ʦ̫", ({ "dingjing shitai", "shitai", "dingjing" }) );
	set("long", "���Ǻ�ɽ�ɵĶ���ʦ̫�������ۣ�üĿ֮����һ�����֮����\n"
			"��Ȼ��Ȼ���й����ϡ�\n");
	set("gender", "Ů��");
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"���"  : (: ask_for_join :),
		"����"  : (: ask_for_join :),
		"join"  : (: ask_for_join :),
		"���������" : (: ask_yao :),
		"����"  : "��ɽ���ӣ����ܻ��ס�",
		
	]));
	set("env/wimpy", 60);	

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield chacngjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
	}));


	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 1500000);
	set("score", 1000);
	set("yao_count", 1);
	
	set_skill("unarmed", 180);
	set_skill("sword", 200);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 150);
	set_skill("baiyun-xinfa",180);	
	set_skill("hengshan-jian", 300);
	set_skill("chuanyun-shou",300);
	set_skill("tianchang-zhang",300); 
	set_skill("lingxu-bu", 250);
	set_skill("literate", 100);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");

	create_family("��ɽ��", 13, "����");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
		return;
	}
	
	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
	}
	if ((int)ob->query("shen")<100000) 
	{
		command( "say �����ܶ�Ϊ����֮�٣����ܳ����²���\n");
		return;
	}

	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
	command("say ϣ������Ŭ�����ƣ��ö��������Թ���Һ�ɽ�ɡ�");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "��" + name[2..3];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");	
	ob->set("name", new_name);
}

string ask_yao()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="dingjing shitai")
		return RANK_D->query_respect(this_player()) + 
		"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("yao_count") < 1 || random(3) > 0)
		return "�������ˣ������������ɸ����ˡ�";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/tianxianggao");
	ob->move(this_player());
	return "�ðɣ���������������ȸ���ɡ�";
}
