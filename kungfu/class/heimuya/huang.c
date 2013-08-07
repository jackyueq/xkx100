// huang.c
inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>;
void create()
{
	set_name("�Ʋ���", ({ "huang boliu","huang","boliu"}) );
	set("gender", "����" );
	set("nickname", HIW"������"NOR);
	set("age", 85);
	set("long", "һ�����룬ֱ�����أ���Ŀ���֮����\n");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 350000);
	set("jiali", 100);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("changquan",70);
	set_skill("tiyunzong", 80);

	map_skill("dodge", "tiyunzong");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("inquiry", ([
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]));

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIC"����������"NOR);
	create_family("��ľ��", 10, "����");

	setup();
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
