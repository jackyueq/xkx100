// Last Modified by winder on Sep. 12 2001
// chang-hezhi.c ����־

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����־", ({ "chang hezhi", "chang", "hezhi" }));
	set("title", HIR"�컨��"HIG"�嵱��"NOR);
	set("nickname", HIB"���޳�"NOR);
	set("long", 
"������ָ����ݣ���ɫ���ƣ��۾��������۽�����һ�����룬üë
бб�ĵ����������������ǿɲ�����������ɻ��µ��˵�ͽ�ܡ���ɰ
�ƵĹ��򣬽����������ܵС��ڰ��޳����ֵ��Ǵ�����������������
һ��ٸ���ƶ�������ĺ���������˵�������������š�\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 500000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("strike", 120);
	set_skill("honghua-shengong", 120);
	set_skill("youlong-shenfa", 180);
	set_skill("heisha-zhang", 180);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("parry", "heisha-zhang");
	map_skill("strike", "heisha-zhang");
	prepare_skill("strike", "heisha-zhang");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({				
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("double_attack", 1);
	create_family("�컨��", 2, "����");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="chang hezhi")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000)
	{
		command("say �Һ컨����ͽ���ϡ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "ƽʱ��Ҫ����һЩ��������֮�£�");
		return;
	}
	command("say �ã�����������˻��������������ˣ�");
	command("recruit " + ob->query("id"));
}

