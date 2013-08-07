// hezudao.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("�����", ({ "he zudao", "he" }));
	set("title", "�����ɿ�ɽ��ʦ");
	set("nickname", "������ʥ");
	set("class", "taoist");
	set("long",
		"�����������ɿ�ɽ��ʦ���ų��ٽ��������ġ�������ʥ����\n"
		"������Ŀ���ݹ����⣬ԼĪ��ʮ��������͡�\n");
	set("gender", "����");
	set("age", 35);
	set("per", 20);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 27);
	set("int", 40);
	set("con", 40);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("combat_exp", 3000000);
	set("score", 400000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		 (: perform_action, "strike.diezhang" :),
		 (: perform_action, "sword.2wu"       :),
		 (: perform_action, "sword.2wu"       :),
	}));

	set_skill("goplaying", 200);
	set_skill("luteplaying", 200);
	set_skill("literate", 180);
	set_skill("leg", 200);
	set_skill("chuanyun-leg", 300);
        set_skill("cuff", 200);
	set_skill("zhentian-cuff", 300);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 200);
	set_skill("dodge", 200);
	set_skill("kunlun-shenfa", 300);
	set_skill("strike", 200);
	set_skill("kunlun-strike", 300);
	set_skill("parry", 200);
	set_skill("sword", 210);
	set_skill("liangyi-sword", 200);
	set_skill("xunlei-sword", 300);
	set_skill("throwing", 180);
	set_skill("mantian-huayu", 250);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("cuff", "zhentian-cuff");
	map_skill("leg", "chuanyun-leg");
	map_skill("strike", "kunlun-strike");
	map_skill("parry", "kunlun-strike");
	map_skill("sword", "liangyi-sword");
	map_skill("throwing", "mantian-huayu");
	prepare_skill("strike", "kunlun-strike");

	create_family("������", 1, "��ɽ��ʦ");
	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/jiaowei-qin");
		if (ob->violate_unique())
		{destruct(ob);ob=new(WEAPON_DIR"changjian");}
	  ob->move(this_object());
	  ob->wield();
	}
	carry_object("/d/kunlun/obj/pao2")->wear();
}

void attempt_apprentice(object ob)
{
	mapping skill;
	string *skl;
	int i;

	if(ob->query_int() < 32 )
	{
		command("say ����������Ҫ���Լ��ߵ��˲ſ������������У��������书�������ۡ�");
		command("say "+RANK_D->query_respect(ob)+"�����Ȼ�ȥ�������ɡ�");
		return;
	}
	if ((int)ob->query_skill("xuantian-wuji", 1) < 85)
	{
		command("say �����黭��ΪС������Ҳ�������������С�");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������޼����϶��µ㹦��");
		return;
	}

	if ((int)ob->query("max_neili", 1) < 500)
	{
		command("say ����������һ�Ķ����������߻���ħ��");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ���Ⱥú�����������");
		return;
	}

       	skill = ob->query_skills();
	skl = keys(skill);
	i = sizeof(skl);
	while (i--)
	{
                if (skill[skl[i]] < 80)
		{
			command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ���" + CHINESE_D->chinese(skl[i]) + 
			"�϶���Щ����");
			return;
		}
	}
	        
	command("recruit "+ob->query("id"));

  if (ob->is_apprentice_of(this_object()))
  if (!ob->query("appren_hezudao"))
	{
		ob->set("appren_hezudao", 1);
//	ob->add("int", 1);
  	command("say ������Ҳ���������ˣ��Ҿͽ���һЩ�ٽ����֪ʶ�ɡ�");
	  ob->set_skill("luteplaying", ob->query_skill("xuantian-wuji", 1));
	  ob->set_skill("goplaying", ob->query_skill("xuantian-wuji", 1));
//	ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
  }
}
