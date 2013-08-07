// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("���ȴ�ʦ", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);


	set("nickname", "�����·���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
/*
        set("chat_chance", 3);
        set("chat_msg", ({
"���ȴ�ʦ̾�˿�����������ϧ������������ɣ���������˲ŵ��䡱\n",
"���ȴ�ʦ��ͷ�����������...�������Զ���֮�����޿���֮�š�\n",
"���ȴ�ʦ��̾��������������ҩҲ���Ǹ�����֮��ţ�ֻ��ϧ��Եδ�ѣ�������ɽ�֡� \n",
        }) );
*/
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 110);
	set_skill("hunyuan-yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 160);
	set_skill("jingang-quan", 160);
	set_skill("unarmed", 110);
	set_skill("finger", 110);
	set_skill("strike", 110);
	set_skill("hand", 110);
	set_skill("claw", 110);
	set_skill("parry", 110);
	set_skill("nianhua-zhi", 160);
	set_skill("sanhua-zhang", 160);
	set_skill("fengyun-shou", 160);
	set_skill("longzhua-gong", 160);
	set_skill("buddhism", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("unarmed", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 36, "����");
	
	set("no_get",1);	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}




