// song.c ��Զ��
// Last Modified by winder on Aug. 18 2002

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("��Զ��", ({ "song yuanqiao", "song" }));
	set("nickname", "�䵱����");
	set("long","������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n��һ���ɸɾ����Ļ�ɫ���ۡ�\n���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
	set("gender", "����");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 120);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 120);
	set_skill("wudang-jian", 120);
	set_skill("wudang-quan", 120);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("�䵱��", 2, "����");

	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "�䵱��" )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 60)
	{
		command("say ���䵱�����ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ����̫�����϶��µ㹦��");
		return;
	}
	if ((int)ob->query("shen") < 35000)
	{
		command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�̫��ʮ��ʽ����\n");
	return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}
