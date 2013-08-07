// hetaichong.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();
string ask_ding();
string ask_su();

void create()
{
	set_name("��̫��", ({ "he taichong", "he" }));
	set("nickname", "��������");
	set("long",
		"���������������š����ｭ��������������̫�塣\n"
		"��Ȼ����Ѵ󣬵���Ȼ���ó�������ʱӢ��������\n");
	set("gender", "����");
	set("class", "taoist");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 40000);

	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("xuantian-wuji", 160);
	set_skill("dodge", 140);
	set_skill("taxue-wuhen", 220);
	set_skill("strike", 80);
	set_skill("kunlun-strike", 120);
	set_skill("parry", 165);
	set_skill("sword", 175);
	set_skill("liangyi-sword", 175);
	set_skill("xunlei-sword", 220);
	set_skill("mantian-huayu", 220);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-cuff", 160);
  set_skill("leg", 155);
	set_skill("chuanyun-leg", 160);

	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-cuff");
	map_skill("parry", "xunlei-sword");
	map_skill("sword", "xunlei-sword");
	map_skill("leg", "chuanyun-leg");
	prepare_skill("cuff", "zhentian-cuff");
	prepare_skill("leg", "chuanyun-leg");
	
	set("no_get",1);

	create_family("������", 4, "������");
	set("class", "taoist");

	set("inquiry",
	([
		"�ķ�" : (: ask_me :),
		"��ϰ֮" : (: ask_su :),
		"׷ɱ" : (: ask_ding :),
	]));

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao2")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
/*
	if((int)ob->query("shen")<0)
	{
		command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+ "��Ʒ��ʵ�����˻��ɡ�");
		command("say "+RANK_D->query_respect(ob)+
			"�����Ȼ�ȥ�������°ɡ�");
		return;
	}
*/
	if(ob->query("gender")=="Ů��")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"�Ϸ�ɲ�����Ů���ӣ���ȥ���ҷ���ȥ�ɡ�");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
		return;
	}

	if(ob->query_skill("xuantian-wuji",1)<100)
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"��������޼���̫��ҿɲ������㡣");
		return;
	}
	command("say �ðɣ��ұ������㣬ֻ����Ͷ��������֮����ð���ѧ�ա�");
	command("recruit " + ob->query("id"));
}


string ask_me()
{
	mapping fam;
	object ob;
        ob = this_player();
	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) +
			"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
//     	if(ob->query("gender")=="����"||ob->query("per")<23)
//		return "�����ľ����������";
	add("book_count", -1);
	ob = new("/clone/book/force-book2");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ������ķ�����\n");
	return "�������б����ķ��������й����������ģ����û�ȥ�ú����У��пն�������Ŷ��";
}

string ask_ding()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) +
			"�뱾��������������֪�˻��Ӻ�̸��";
		
	if(this_player()->query_skill("mantian-huayu",1) < 60)
		return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬����ȥ�ɣ�";

	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
			"���������ϲ���������ô����Ҫ�ˣ�";
	if (query("ding_count") < 1)
		return "ɥ�Ŷ��Ѹ�������ȥ׷ɱ��ϰ֮���ˣ���Ͳ���ȥ�ˡ�";
	add("ding_count", -1);
	this_player()->set_temp("kunlun/ding",1);
	ob = new("/d/kunlun/obj/sangmending");
	ob->move(this_player());
	return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬���ɥ�Ŷ������ȥ�ɡ�";
}
string ask_su()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) +
			"�뱾��������������֪�˻��Ӻ�̸��";
		
	if(this_player()->query_temp("kunlun/ding",1))
		return "�㻹����������ʲô��������ȥ׷��ϰ֮��";
	return "��ϰ֮��һﾹȻ��͵�����ɵ������񽣣����ɵ��ӱص�����׷ɱ��";
}
