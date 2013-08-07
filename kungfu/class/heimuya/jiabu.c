// jiabu.c
#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;

void greeting(object me, object ob);
string ask_me();
void init();
void create()
{
	set_name("�ֲ�", ({ "jia bu", "jia", "bu"}) );
	set("gender", "����" );
	set("age", 45);
	set("long", "����������������̫��Ѩ�߸߹��𣬱������һöö�����Ƶġ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 40);

	set("per", 15);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("jiali", 200);
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");

	set("inquiry", ([
		"�������" :    (: ask_me :),
		"���"     :    (: ask_me :),
	]));

	set("party/party_name",HIG"����"NOR);
	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIG"�����ó���"NOR);
	create_family("��ľ��", 9, "����");

	set("chat_chance", 2);
	set("chat_msg", ({
		 "�ֲ�̾��: ��������Ȱ��ڣ��������Ʊ������Ǳ�����֪�����������ӡ���\n"
        }) );
	setup();
        carry_object("/d/heimuya/npc/obj/dadao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
     command("say �����Ƥë�����ң����ң�\n");
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	add_action("do_join","join");
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_me()
{
	return "����������������(join riyuejiao)��";
}

#include "riyuejiao.h"
#include "shenjiao.h"
