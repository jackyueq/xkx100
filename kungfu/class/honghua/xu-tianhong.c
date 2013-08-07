// Last Modified by winder on Sep. 12 2001
// xutianhong.c �����

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "xu tianhong", "xu", "tianhong" }));
	set("nickname", HIM"�����"NOR);
	set("title", HIR"�컨��"HIG"�ߵ���"NOR);
	set("long","���Ǻ컨����ߵ��ң�\n����ͺ�������ʮ���£���İ�С�����Ƕ�ı���Ǻ컨������Ҿ�ʦ���书Ҳ�Ĳ������侲���ء�\n");
	set("gender", "����");
	set("class", "swordman");
	set("age", 40);
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
	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("force", 120);
	set_skill("honghua-shengong", 120);
	set_skill("dodge", 120);
	set_skill("youlong-shenfa", 180);
	set_skill("hand", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("zhuihun-jian", 180);
	set_skill("benlei-shou", 180);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("hand", "benlei-shou");

	create_family("�컨��", 2, "����");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < 1000 &&
		ob->query("family/master_id")=="xu tianhong")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 2000)
	{
		command("say �Һ컨����ͽ���ϡ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "ƽʱ��Ҫ����һЩ��������֮�£�");
		return;
	}
	command("say �ã�����������˻��������������ˣ�");
	command("recruit " + ob->query("id"));
}


