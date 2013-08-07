// fanyao.c
// Last Modified by winder on Oct. 30 2001

#include "ansi.h";
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
	set_name("��ң", ({"fan yao","fan","yao",}));
	set("long",
		"����һλ�������е�ͷ�ӣ����ײ����ۡ�\n"
		"�����������߰˰˵�ȫ���˰̣���ֱ������������Ŀ�ˡ�\n"
	);

	set("nickname", HIY "��ң����" NOR);
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 800000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("cuff", 180);
	set_skill("strike", 180);
	set_skill("claw", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("sword", 180);
	set_skill("qingfu-shenfa", 200);
	set_skill("jiuyang-shengong", 180);
	set_skill("lieyan-dao", 250);
	set_skill("liehuo-jian", 250);
	set_skill("sougu", 200);
	set_skill("hanbing-mianzhang", 200);
	set_skill("qishang-quan", 200);
	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("claw", "sougu");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("cuff", "qishang-quan");
	map_skill("blade", "lieyan-dao");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	prepare_skill("claw", "sougu");

	set("inquiry", ([
		"����ʥ����" : (: ask_me :),
		"����ʥ����" : (: ask_me :),
		"ʥ����"     : (: ask_me :)
	]));

	set("env/wimpy", 60);
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: prepare_skill("finger", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );
	set("party/party_name",HIG"����"NOR);
	set("party/rank",HIR"������ʹ"NOR);
	create_family("����", 34, "����");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ���ͽ�ģ����Ҹ�λ����ȥ��");
	return 0;
}

#include "fanyao.h"
