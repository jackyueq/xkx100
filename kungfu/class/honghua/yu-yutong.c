// Last Modified by winder on Sep. 12 2001
// yu-yutong.c ����ͬ

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;

void create()
{
	set_name("����ͬ", ({ "yu yutong", "yu" }));
	set("nickname", YEL"������"NOR);
	set("title", HIR"�컨��"HIG"ʮ�ĵ���"NOR);
	set("long","���Ǻ컨���ʮ�ĵ��ң�\n��һ����Ϊ����İ�ɫ������\n����ͺ����ڶ�ʮ���£�����ɫ����������������ü��Ŀ�㣬����Ӣ����������\n���ǽ��������ӵܣ��й���š�\n�������һ�Һ�����һ��صأ���˾�����ҵ������ֱ����Ž���ݺ����������С�\n����ͬһ�����ߣ�������Ե��������Ϊʦ������ϰ�䣬����ʿ��������������\n��Ϊ�˻������ɣ���ʶ������̸���ڻ����������ķ�����̽ѶϢְ֮��\n");
	set("gender", "����");
	set("class", "swordman");
	set("age", 21);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 400000);
	set("score", 100000);

	set_skill("force", 80);
	set_skill("honghua-shengong", 80);
	set_skill("dodge", 80);
	set_skill("youlong-shenfa", 120);
	set_skill("hand", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("benlei-shou", 120);
	set_skill("zhuihun-jian", 120);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("hand", "benlei-shou");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�컨��", 2, "����");

	setup();
	carry_object("/kungfu/class/baituo/obj/baipao")->wear();
	carry_object(__DIR__"obj/yaodai")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="yu yutong")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0)
	{
		command("say �Һ컨����ͽ���ϡ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "ƽʱ��Ҫ����һЩ��������֮�£�");
		return;
	}
	command("say �ã�����������˻��������������ˣ�");
	command("recruit " + ob->query("id"));
}

