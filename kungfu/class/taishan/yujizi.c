// Last Modified by winder on Aug. 25 2001
// yujizi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("������", ({ "yuji zi", "zi", "yuji" }) );
	set("gender", "����");
	set("class", "taoist");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2000);
	set("max_neili", 2000);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("combat_exp", 1800000);
	set("shen_type", -1);

	set_skill("strike", 200);
	set_skill("kuaihuo-strike", 300);
	set_skill("sword", 200);
	set_skill("taishan-sword", 300);
	set_skill("force", 200);
	set_skill("panshi-shengong", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("fengshenjue", 300);

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

	create_family("̩ɽ��", 12, "����");
	setup();

	carry_object(WEAPON_DIR+"sword/houjian")->wield();
	carry_object(CLOTH_DIR+"daopao")->wear();
}

void attempt_apprentice(object ob)
{
	if((int)ob->query_skill("panshi-shengong",1) < 140)
		command("say ��ı����ķ����ö����ϰ��");
	else
	{
		command("say �ð������Ҿ�������ɡ�");
		command("recruit " + ob->query("id") );
	}
}


