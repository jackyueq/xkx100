// goudu.c ����
// Modified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>;
string ask_me();

void create()
{
	set_name("����", ({ "gou du", "gou" }));
	set("nickname","�����Ȱ��ѡ����");
	set("long","������ȥҲ�Ǽ�ʮ������ˣ��Ժö��飬���Ӱټң�������������һλ����ѧ�ʵ����壬ȴ�Ǵ�Ȼһ������ӵ�ģ����\n");
	set("gender", "����");
	set("age", 44);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);

	set("inquiry", ([
		"����":(:ask_me:),
	]) );

	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	set("combat_exp", 360000);
	set("score", 40000);

	set_skill("literate", 100);
	set_skill("blade", 80);
	set_skill("ruyi-dao", 120);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("hand", 80);
	set_skill("parry", 80);
	set_skill("lingboweibu", 120);
	set_skill("beiming-shengong",80);
	set_skill("zhemei-shou", 120);
	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("hand", "zhemei-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set("book_count", 1);

	create_family("��ң��", 3, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ��ң�ɳ�������");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me,ob;
	ob=this_player(); 

	if (query("book_count") < 1)
		return "�������ˣ��Ǳ���������Ѿ����͸������ˡ�";   
	add("book_count", -1);                  

	if(ob->query("family/master_id")=="xiaoyao zi")
	{
		command("say ʦ����Ҫ���������ȥ���ǡ�");
		message_vision(HIY"�����ӻ����ͳ�һ�����飬���˸�$N \n\n"NOR,ob);
		me=new("/clone/book/lbook5");
		me->move(ob);
		return "�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n";
	}
	command("say �������������û���ˣ����������ɸ��ִ����ֵ������顣");
	command("say ��Ȼ����ô��ѧ���ҾͰ����͸���ɡ�\n");
	message_vision(HIY"�������䵹�����˰��죬�ҳ�һ�����飬���˸�$N \n\n"NOR,ob);
	if (random(2) == 1) me=new("/clone/book/strike_book");
	else me=new("/clone/book/book-paper");
	me->move(ob);

	return "�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n";
}
