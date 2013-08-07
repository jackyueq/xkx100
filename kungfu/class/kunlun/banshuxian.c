// banshuxian.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("�����", ({ "ban shuxian", "ban" }));
	set("title", "���������ŷ���");
	set("long",
"����һ����ĸߴ�İ���Ů�ӣ�ͷ�����ף�˫Ŀ������ü�ļ��
��ɷ�������������������š����ｭ��������������̫��ķ��ˡ�
������������ɵġ�̫�����š�������̫��Ҳ�������֣���ʮ��
��������ɽ����ָ��ʹ���ˣ������﷽Բ֮�ڣ�ٲȻŮ��һ�㡣\n");
	set("gender", "Ů��");
	set("class", "swordman");
	set("age", 44);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("per", 20);
	set("str", 26);
	set("int", 24);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 40000);

	set_skill("literate", 120);
	set_skill("force", 155);
	set_skill("xuantian-wuji", 160);
	set_skill("dodge", 145);
	set_skill("taxue-wuhen", 225);
	set_skill("strike", 60);
	set_skill("kunlun-strike", 90);
	set_skill("parry", 160);
	set_skill("sword", 170);
	set_skill("leg", 140);
	set_skill("chuanyun-leg", 220);
	set_skill("liangyi-sword", 170);
	set_skill("xunlei-sword", 220);
	set_skill("mantian-huayu", 220);
	set_skill("throwing", 165);

	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("leg", "chuanyun-leg");
	map_skill("parry", "liangyi-sword");
	map_skill("sword", "liangyi-sword");
	prepare_skill("leg", "chuanyun-leg");
	set("inquiry",
	([
		"�ؼ�" : (: ask_me :),
	]));
	set("book_count", 1);
	set("env/wimpy", 60);
	create_family("������", 4, "���ŷ���");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao2")->wear();
}

void attempt_apprentice(object ob)
{
/*
	if((int)ob->query("shen")<0)
	{
		 command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+"��Ʒ��ʵ�����˻��ɡ�");
		command("say "+RANK_D->query_respect(ob)+"�����Ȼ�ȥ�������°ɡ�");
		return;
	}
*/
	if(ob->query("gender")=="����")
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"������Щ�������Ҽ��˾ͷ���������߿���");
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
	command("say �ðɣ��Ժ���͸���ѧ�书�ɣ�����ð���ѧ�գ�����������");
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
	if(ob->query("gender")=="����")
		return "�����߿����ҿ���������Щ�����˾ͷ���";
	if (query("book_count") < 1)
		return "�������ˣ������澭�ѱ���ʦ�������ˡ�";
	add("book_count", -1);
	ob = new("/clone/book/lyj-book.c");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ����ǽ��ĵ�����\n");
	return "��ʦ���������Ȿ�����ǽ��ĵá������û�ȥ�ú����С�";
}

