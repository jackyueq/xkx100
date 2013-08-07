// Last Modified by winder on Sep. 12 2001
// wuchen.c �޳�����

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�޳�����", ({ "wuchen daozhang", "wuchen" }));
	set("title", HIR"�컨��"HIG"������"NOR);
	set("nickname", HIB"׷�������"NOR);
	set("long", "���Ǻ컨�����ڶ��ѽ��ε��޳�������\n�컨��������������ã�\n����ͺ�������ʮ�����ң�������������º����޷��Զ������ϱ��鲻ŭ������\n");
	set("gender", "����");
	set("class", "taoist");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 23);
	set("con", 26);
	set("dex", 27);
	set("max_qi", 2200);
	set("max_jing", 2000);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
	set("combat_exp", 3500000);
	set("score", 160000);
	set_skill("force", 180);
	set_skill("honghua-shengong",180);
	set_skill("dodge", 180);
	set_skill("youlong-shenfa", 180);
	set_skill("hand", 180);
	set_skill("benlei-shou", 180);
	set_skill("parry", 180);
	set_skill("sword", 190);
	set_skill("zhuihun-jian", 190);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	map_skill("hand", "benlei-shou");
	prepare_skill("hand", "benlei-shou");

        set("env/wimpy", 60);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhuihun" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

	create_family("�컨��", 2, "����");
	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init()
{
	object ob = this_player();

	::init();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="wuchen daozhang")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���Һ컨���������㣡\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000)
	{
		command("say �ߣ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "Ϊ��֮���ƺ�����ô����");
		return;
	}
	command("say ���������Ҿ��������ˣ�");
	command("recruit " + ob->query("id"));
}

