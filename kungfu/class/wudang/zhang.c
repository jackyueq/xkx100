// zhang.c ������

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();
string ask_zhenwu();

void create()
{
	object ob;
	set_name("������", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "��������");
	set("long", 
"�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������л��书������
�󡢼��������Ĵ���ʦ�����������ȭ�����ҳ���Բ֮ͨ����
�����澭�����ص��ڹ��෢���������˻�ӳ��������ҫǧ�ŵ���
��һ���书���˺������α�������������ͦ�㣬׿���ƺ�������
ѧ�����������Ժ����ᡣ
��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷�����ĸߴ��������꣬��
����⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 300);
	set_skill("wudang-quan", 300);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
		"���佣" : (: ask_zhenwu : ),
	]));
	set("book_count", 1);
	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/zhenwu-jian");
		if ( ob->violate_unique())
      destruct(ob);
    else
      {
      	ob->move(this_object());
      	ob->wield();
    	}      
	}
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}
void init()
{
	object ob;
	mapping myfam;

	::init();
	if (interactive(ob=this_player()) && ob->query("family"))
	{
		if (ob->query("family/master_id") == "zhang sanfeng" &&
			ob->query("shen") < -100 )
		{
			command("say "+RANK_D->query_rude(ob)+ "�������������������Ϊ��\n");
			command("expell " + ob->query("id"));
			add_action("do_qiecuo","qiecuo");
			return;
		}
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "�䵱��")&&(!ob->query_skill("taiji-shengong",1))&&(ob->query("combat_exp")>500000))
       		{
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + ob->query("id"));
        	}
	add_action("do_qiecuo","qiecuo");
	}
	
	add_action("do_qiecuo","qiecuo");
}

string ask_zhenwu()
{
	object player = this_player();

	if( !player->query("wudang/zhenwu") )
		return "�����佣����ƶ������ʱ���õı��С�";
}
void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "�䵱��" )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 100) {
		command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ����̫�����϶��µ㹦��");
		return;
	}
	if ((int)ob->query_skill("taoism", 1) < 80)
	{
		command("say ���䵱���˵����书��������书�벻����ѧ�ķ���");
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�������¾���");
		return;
	}
	if ((int)ob->query("shen") < 200000)
	{
		command( "say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) + "�Ƿ����ò�����");
		return;
	}
	if (ob->query_int() < 30)
	{
		command( "say ���䵱���书ȫ�ӵ��������");
		command( "say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("chat ����������������");
	command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�" + ob->name() + "��ôһ������֮�ţ����ǿ�ϲ�ɺء�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��书�ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/taiji-book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�̫��ȭ������\n");
	return "�ðɣ��Ȿ��̫��ȭ�������û�ȥ�ú����С�";
}

