// zuo.c

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>;

string ask_book();
string ask_book1();
void create()
{
	set_name("������", ({ "zuo lengchan", "zuo" }) );
	set("title", HIR"������������"HIY"��ɽ�ɵ�ʮ������"NOR);
	set("gender", "����");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 3000000);
	set("shen", -200000);
	set("book_count", 1);
	set("book_count1", 1);

	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("songshan-sword", 300);
	set_skill("songyang-strike", 300);
	set_skill("poyun-hand", 300);
	set_skill("hanbing-zhenqi", 200);
	set_skill("fuguanglueying", 300);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("inquiry",([
		"�ؼ�"	     : (: ask_book :),
		"����"	     : (: ask_book :),
		"����������" : (: ask_book :),
		"����"	     : (: ask_book1 :),
		"��ɽ����"   : (: ask_book1 :),
	]));

	create_family("��ɽ��", 13, "����");
	setup();

	carry_object(WEAPON_DIR+"kuojian")->wield();
	carry_object(__DIR__"obj/yellow-cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	command("say ����Ϊ������������������������������ɽһ�ɡ�");
	command("recruit " + ob->query("id"));
}

string ask_book()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/songyang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ���������������\n");
	return "�ðɣ��Ȿ�����������ס����û�ȥ�ú����С�";
}

string ask_book1()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count1") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count1", -1);
	ob = new("/clone/book/sword_book4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ���ɽ��������\n");
	return "�ðɣ��Ȿ����ɽ���ס����û�ȥ�ú����С�";
}
