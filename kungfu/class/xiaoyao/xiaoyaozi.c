// xiaoyaozi.c ��ң��
// Modified by Winder June.25 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("��ң��", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("title", "��ң�ɿ�ɽ��ʦ");
	set("long", 
		"��������ң�ɿ�ɽ��ʦ��������Ϊ��ң������һ���ڽ�����\n"
		"�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
		"����ȴ�ǡ���������������Ѯ��������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);
	
	set("max_qi", 5500);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jingli", 2000);
	set("max_jingli", 2000);
	set("jiali", 100);
	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("beiming-shengong", 200);
	set_skill("dodge", 200);
	set_skill("lingboweibu", 300);
	set_skill("strike", 200);
	set_skill("liuyang-zhang", 300);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("ruyi-dao", 300);
	set_skill("zhemei-shou", 300);
	set_skill("hand", 200);
	set_skill("literate", 120);
	set_skill("luteplaying", 150);
	set_skill("goplaying", 150);
	set_skill("literate", 100);
	set_skill("painting", 150);
	set_skill("medicine", 150);
	set_skill("construction", 150);
	set_skill("horticulture", 150);
	set_skill("dramaturgy", 150);
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("��ң��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 80) {
		command("say ����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�ı�ڤ���Ƿ�Ӧ��������߰���");
		return;
	}

	if (ob->query_int() < 35) {
		command("say ����ң���书�����ӡ���ң�����֡�");
		command("say ����ν����ң������ֻ�ܿ����Լ�ȥ����");
		command("say ����" + RANK_D->query_respect(ob) + "�������ƺ����д���߰���");
		return;
	}
	command("smile");
	command("say �벻���������Ͼ�Ȼ�����˿��Լ̳��ҵ���ң�ķ���");
	command("recruit " + ob->query("id"));
	ob->set("title","��ң�ɻ���ʹ��");
}
