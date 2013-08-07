// yulingzi.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "yuling zi","yuling", "zi" }));
	set("long",
		"�������ɵ�������ӣ�������������ķ���������Ͷ�����ŵ�����֮�⡣\n");
	set("gender", "Ů");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 26);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 850);
	set("max_qi", 850);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 30);
	set("combat_exp", 380000);
	set("score", 4000);

	set_skill("force", 95);
	set_skill("xuantian-wuji", 105);
	set_skill("dodge", 95);
	set_skill("taxue-wuhen", 125);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("xunlei-sword", 155);
	set_skill("leg", 90);
	set_skill("chuanyun-leg", 120);
	set_skill("throwing", 80);
	set_skill("mantian-huayu", 95);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-jian");
	map_skill("leg", "chuanyun-leg");
	map_skill("sword", "xunlei-jian");
	prepare_skill("leg", "chuanyun-leg");

	create_family("������", 5, "����");
	set("env/wimpy", 60);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="����")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"��ʦĸ��׼�����е��ӣ���ȥ����ʦ��ȥ�ɡ�");
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

