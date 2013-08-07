// ji.c ����ܽ

inherit NPC;
inherit F_MASTER;
int ask_jian();

void create()
{
	set_name("����ܽ", ({ "ji xiaofu","ji","xiaofu"}));
	set("long", "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�ƫ��ƫ���������������\n"
		"�������������ȹ�����\n");
	set("gender", "Ů��");
	set("age", 22);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("shen", 10000);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("inquiry",([
		"���콣" : (:ask_jian:),
		"������" : "����û�������������콣������һ����",
		"���" : "�ҵ�Ů���������������֪��ô��",
		"����"   : "���Ⱳ���ǲ�ָ���������ˡ�",
		"���"   : "ʦ������̫ƫ�ġ�",
	]));

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("throwing", 40);
	set_skill("persuading", 40);
	set_skill("force", 60);
	set_skill("dodge", 80);
	set_skill("finger", 70);
	set_skill("parry", 70);
	set_skill("strike", 70);
	set_skill("sword", 80);
	set_skill("jinding-zhang", 100);
	set_skill("tiangang-zhi", 100);
	set_skill("huifeng-jian", 120);
	set_skill("zhutian-bu", 120);
	set_skill("linji-zhuang", 70);

	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
//		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
	create_family("������", 4, "����");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
		command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if ((int)ob->query("combat_exp") > 100) {
		command("say �Ҷ���ע�����ޣ��Ե���Ҫ�������ܼ�į��");
		command("say �ڽ����������棬" + RANK_D->query_respect(ob) +
			"�����ḻ���Ƿ����ڶ����޵���");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
int ask_jian()
{
	object ob = this_player();
	ob->set("marks/ji",0);
	ob->set("marks/skysword",1);
	say( "����ܽ΢΢̾�˿����������콣�����������¡���\n");
	tell_object(ob,"˵�꣬��ƮȻԾ��������ȥ������Ʈ�������Ƶ������˸ж�����\n");
	call_out("goway",2);
	return 1;
}
void goway()
{
	destruct(this_object());
}
