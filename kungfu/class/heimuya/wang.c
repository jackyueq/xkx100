// wang.c
#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;
string ask_me();
void init();

void create()
{
	set_name("����", ({ "wang cheng","wang"}) );
	set("gender", "����" );
	set("age", 65);
	set("long", "������İ��֣�������Ц����ʵΪ��ʮ�ֺݶ���\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 150);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("sword",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	set("inquiry", ([
		"�������" :    (: ask_me :),
		"���"     :    (: ask_me :),
	]));

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIC"����������"NOR);
	create_family("��ľ��", 10, "����");

	setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ��յ��ӡ�\n");
	return;
}

string ask_me()
{
	return "���������������̾͵�ȥ���Ĵ��ϡ�";
}
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

//	add_action("do_join","join");
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}
#include "riyuejiao.h"

