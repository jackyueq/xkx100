// fanbailing.c ������
// Modified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>;
string ask_me();

void create()
{
	set_name("������", ({ "fan bailing", "fan" }));
	set("long", "��ʦ�Ӵϱ�������ѧ����Χ�壬�������£����е��֡�\n");
	set("nickname","�����Ȱ��ѡ���ħ");
	set("gender", "����");
	set("age", 48);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("inquiry", ([
		"����":(:ask_me:),
	]) );
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 380000);
	set("score", 50000);

	set_skill("goplaying",150);
	set_skill("blade", 90);
	set_skill("ruyi-dao", 130);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("strike", 90);
	set_skill("parry", 90);
	set_skill("lingboweibu", 130);
	set_skill("beiming-shengong",90);
	set_skill("liuyang-zhang", 130);

	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("book_count", 1);
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

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
		return "�������ˣ��������Ѿ����͸������ˡ�";   

	add("book_count", -1);                  
	command("say �ðɣ����ҾͰ����͸����ˡ�\n");
	message_vision(HIY"������΢Ц�Ŵӻ����ó���һ���飬���˸�$N\n\n"NOR,ob);
	me=new("/clone/book/hand_book");
	me->move(ob);
	return "�Ȿ���׿�ǧ��Ҫ�������ˡ�\n";
}
