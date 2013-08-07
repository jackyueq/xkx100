// jiangtao.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "jiang tao", "jiang"}));
	set("long",
		"������ɫ���ۣ�����б�峤������ʮ�˾�����͡�\n"
		"���ֺ�˪��һ��Ҫ�������ǵ�ģ����\n");
	set("gender", "����");
	set("age", 20);
	set("class", "taoist");
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per", 16);
	set("str", 26);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 65);
	set_skill("xuantian-wuji", 60);
	set_skill("dodge", 65);
	set_skill("taxue-wuhen", 60);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei-sword", 65);
	set_skill("cuff", 55);
	set_skill("zhentian-cuff", 70);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-sword");
	map_skill("cuff", "zhentian-cuff");
	prepare_skill("cuff", "zhentian-cuff");
	create_family("������", 5, "����");
	set("env/wimpy", 60);
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

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say ʦ�����ҿ������Ц����ȴ�����򲻸ҵģ�");
		return;
	}

	command("say �ðɣ��Ҿ������㣬����һЩƤë����");
	command("recruit " + ob->query("id"));
}

