// Last Modified by Sir on May. 22 2001
// qing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
#include <command.h>;
void create()
{
	set_name("����", ({ "yi qing", "qing" }) );
	set("long", "����һλ����Ů�ᣬ��ü��Ŀ��\n");
	set("gender", "Ů��");
	set("class", "bonze");
	set("age", 35);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 30);
	set("max_qi", 1500);
	set("max_jing", 800);
	set("combat_exp", 500000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("sword", 90);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 90);
	set_skill("strike", 70);
	set_skill("hand", 80);
	set_skill("buddhism", 100);
	set_skill("baiyun-xinfa",100);	
	set_skill("hengshan-jian", 150);
	set_skill("chuanyun-shou",120);
	set_skill("tianchang-zhang",100); 
	set_skill("lingxu-bu", 120);
	set_skill("literate", 50);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");
	prepare_skill("strike", "tianchang-zhang");
	prepare_skill("hand", "chuanyun-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yuyin" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),		
		(: exert_function, "recover" :),
	}) );


	create_family("��ɽ��", 14, "����");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("combat_exp") > 10000 && ob->query("family/family_name")!="��ɽ��")
	{
		command("say �Һ�ɽ��ע�����ޣ��Ե���Ҫ�������ܼ�į��");
		command("say �ڽ����������棬" + RANK_D->query_respect(ob) +
			"�����ḻ���Ƿ����ں�ɽ�޵���");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say �Һ�ɽ����������������֮һ���Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if (ob->query("gender") != "Ů��") 
	{
		command("say �Һ�ɽֻ��Ůͽ��");		
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
