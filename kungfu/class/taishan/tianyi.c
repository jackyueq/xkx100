// Last Modified by winder on Aug. 25 2001
// tianyi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("���ҵ���", ({ "tianyi daoren", "daoren", "tianyi" }) );
	set("gender", "����");
	set("class", "taoist");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 1400);
	set("max_neili", 1400);
	set("max_qi", 1200);
	set("max_jing", 800);
	set("combat_exp", 500000);
	set("shen_type", 1);

	set_skill("strike", 80);
	set_skill("kuaihuo-strike", 120);
	set_skill("sword", 80);
	set_skill("taishan-sword", 120);
	set_skill("force", 80);
	set_skill("panshi-shengong", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("fengshenjue", 120);

	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("̩ɽ��", 13, "����");
	setup();

	carry_object(WEAPON_DIR+"sword/houjian")->wield();
	carry_object(CLOTH_DIR+"daopao")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	string family;

	family=(string)ob->query("family/family_name");
	if(family!="̩ɽ��")
		command("say "+RANK_D->query_respect(ob)+"���Ǽ�����̩ɽ�ɣ����ܹ���ɣ�");
	else command("nod "+ob->query("id"));
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("mingwang")<0)
		command("say ��̩ɽ�ɵ��Ӷ�����������֮����"+RANK_D->query_respect(ob)+"�����Ĳ�������");
	else
	{
		command("say �ð������Ҿ�������ɡ�");
		command("recruit " + ob->query("id") );
	}
}

