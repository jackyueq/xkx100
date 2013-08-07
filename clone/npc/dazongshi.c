// dazongshi.c ����ʦ

#include <ansi.h>;
inherit NPC;
string ask_me();

void create()
{
	set_name("����ʦ", ({ "da zongshi", "zongshi" }));
	set("long","�����ǽ����Ĵ���ʦ����ֻ����������ս�����ܻ�ý�������ʵ���͵�λ�ĳ��ϡ�\n");
	set("gender", "����");
	set("age", 40);
	set("class", "taoist");
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("no_get",1);

	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jingli", 100);
	set("max_jingli", 100);
	set("tili", 100);
	set("jiali", 100);
	set("food", 400);
	set("water", 400);
	set("combat_exp", 5000000);
	set("score", 500000);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_skill("force", 300);
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 300);
	set_skill("taiji-quan", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 300);
	set_skill("wudang-jian", 300);
	set_skill("wudang-quan", 300);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "taiji-jian");
	set("inquiry", ([
		"��ɱ" : (: ask_me :),
		"����" : (: ask_me :),
		"ɱ��" : (: ask_me :),
		"��ս" : (: ask_me :),
		"Ʒ��" : (: ask_me :),
		"�书" : (: ask_me :),
	]));
	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}
string ask_me()
{
	object me = this_player(), ob = this_object();

	if ( me->query("combat_exp") < 500000)
		return "����ľ���չ�����ʮ���������Ұɡ�";
	ob->set("killer/id", me->query("id"));
	ob->set("killer/time", time());
	set("eff_qi", 6000);
	set("eff_jing", 3000);
	set("qi", 6000);
	set("jing", 3000);
	set("food", 400);
	set("water", 400);
	set("neili", 5000);
	set("jiali", 100);
	command("yun powerup");
	set("neili", 5000);
	set("jiali", 100);
	return "�ðɣ��Ǿ����ɡ�";
}
void die()
{
	object *me, ob = this_object(); //,mm = this_player();
	int i, sc, new_killer;

//	sc = mm->query("score");
	me = all_inventory(environment(ob));
	for (i = 0; i < sizeof(me); i ++)
		if( me[i]->query("id") == ob->query("killer/id") )
		{
			sc = me[i]->query("score");
			new_killer = 12345/(time() - ob->query("killer/time"));
			if (me[i]->query("KILLER") >= new_killer )
			{
				tell_object(me[i],HIR"\n����ʦ����ǰ�����㣺��û�н���������һ�ˡ���\n"NOR);
			        if(me[i]->quert("zongshi_winner")<3)  me[i]->add("score", -5000);
			}
			else
			{
				tell_object(me[i],HIR"\n����ʦ����ǰ�����㣺���ã��ã��ã�û�а�����һ�ˡ���\n"NOR);
				message("channel:chat", HIM"�����ġ�ĳ�ˣ�"+me[i]->query("name")+chinese_number(time()-ob->query("killer/time"))+"���д�ɱ����ʦ�ɹ���\n"NOR, users());
				me[i]->set("KILLER", new_killer);
				me[i]->add("zongshi_winner", 1);
			        if(me[i]->quert("zongshi_winner")<3)  me[i]->add("score", 10000);
			}
		}
	::die();
}

