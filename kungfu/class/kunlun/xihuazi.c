// xihuazi.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "xi huazi", "xi" }));
	set("long",
		"���������ɵ�������ӣ�������ף�����ʮ�ֱ��ꡣ\n");
	set("gender", "����");
	set("class", "taoist");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 15);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 800);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 400000);
	set("score", 1000);

	set_skill("force", 95);
	set_skill("xuantian-wuji", 105);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 120);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("xunlei-sword", 150);
	set_skill("cuff", 105);
	set_skill("zhentian-cuff", 150);
	set_skill("throwing", 80);
	set_skill("mantian-huayu", 120);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-sword");
	map_skill("cuff", "zhentian-cuff");
	prepare_skill("cuff", "zhentian-cuff");

	create_family("������", 5, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="Ů��")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"��ʦĸ��׼����Ů���ӣ���ȥ����ʦ�ȥ�ɡ�");
		return;
	}
	if(ob->query_skill("xuantian-wuji",1)<60)
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"��������޼���̫��ҿɲ������㡣");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
		return;
	}
	command("say ��Ȼ"+RANK_D->query_respect(ob)+
		"��ôŬ�����Ҿ�������ɡ�");
	command("recruit " + ob->query("id"));
}

