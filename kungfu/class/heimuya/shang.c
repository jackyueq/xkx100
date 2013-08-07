// shang.c
#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;

void greeting(object me, object ob);
string ask_me();
void init();
void create()
{
	set_name("�Ϲ���", ({ "shangguan yun","shangguan","yun"}) );
	set("gender", "����" );
	set("age", 40);
	set("long", "�����ֳ���, ˫Ŀ�����Ȼ, �������ơ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);

	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 360000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu-bufa", 120);
	set_skill("lingshe-zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	set("inquiry", ([
		"�������" :    (: ask_me :),
		"���"     :    (: ask_me :),
	]));

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIW"�׻��ó���"NOR);
	create_family("��ľ��", 9, "����");

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/heimuya/npc/obj/zhenzhu");
}

void attempt_apprentice(object ob)
{
	command("say ��ֻ�ܽ�����̣����յ��ӡ�\n");
	return;
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
