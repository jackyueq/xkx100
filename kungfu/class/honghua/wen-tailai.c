// wen-tailai.c ��̩��
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��̩��", ({ "wen tailai", "wen", "tailai" }));
	set("title", HIR"�컨��"HIG"�ĵ���"NOR);
	set("nickname", HIM"������"NOR);
	set("long","���Ǻ컨����ĵ��ң���һ����ɫ������\n����ͺ�������ʮ���£����ʮ�ֻ��࣬˫�����ͻ�����������ϼ롣ʮ�������˵������������²�֪���й�������������ͽ��ԡ�\n");
	set("gender", "����");
	set("class", "swordman");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2000);
	set("max_jing", 1500);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
	set("combat_exp",800000);
	set("score", 100000);

	set_skill("force", 100);
	set_skill("honghua-shengong", 100);
	set_skill("dodge", 100);
	set_skill("youlong-shenfa", 150);
	set_skill("hand", 100);
	set_skill("benlei-shou", 250);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("qiuge-dao", 150);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "qiuge-dao");
	map_skill("blade", "qiuge-dao");
	prepare_skill("hand", "benlei-shou");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("�컨��", 2, "����");
	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="wen tailai")
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

