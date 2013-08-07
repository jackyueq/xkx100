// Npc: /d/lingxiao/npc/zhang.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
string ask_jiu();

void create()
{
	set_name("�����",({"zhang wanfeng","zhang"}));
	set("gender", "����");
	set("age", 20);
	set("long", "���������ǵ�������������磬������Ⱦƺȵø��ˡ�\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("qi", 1200);
	set("max_qi", 1200);
	set("inquiry", ([
	    "jiu"      : (: ask_jiu :), 
	    "�������" : (: ask_jiu :), 
	]) ); 
	set("jiu_count", 2);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 60);
	set_skill("snow-strike", 60);
	set_skill("snowstep", 60);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("������", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian");
	carry_object(CLOTH_DIR+"bai")->wear();
}

string ask_jiu()
{
	object ob;

	if (this_player()->query_skill("force", 1) < 50)
		return "���¿����Ͳ��Ǹ�����֮�ˣ�����Ұ�";
//	if (this_player()->query("family/family_name") != "������")
//		return RANK_D->query_respect(this_player()) +"���·����������ӣ���ΪʲôҪ���������ƣ�";
	if ( present("shenyang yujiu", this_player()) )
		return RANK_D->query_respect(this_player()) +"�����Ͼ���һ��������Ҫ������ô̰�ģ�"; 
	if (query("jiu_count") < 1)
		return "��ѽѽ������þƵ��˻��治�٣��Բ��𣬲�������Ѿ������ˡ�";
	if (random(5) != 0)
	{
		add("jiu_count", -1);
		command("wield sword");
		command("unwield sword");
		return "����ʦ�������ʣ������ô����ľ����ˡ����������ҡ�";
	}
	ob = new(NOSTRUM_DIR"shenyangjiu");
	ob->move(this_player());
	add("jiu_count", -1);
	message_vision("$N�ӹ�һ��������ơ�\n",this_player());
	return "��ȥ�ɣ���Ҫ���ƺ�ѽ��";
}

