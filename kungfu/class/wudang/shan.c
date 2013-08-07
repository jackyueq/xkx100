// shan.c �Ŵ�ɽ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ŵ�ɽ", ({ "zhang cuishan", "zhang" }));
	set("nickname", "�䵱����");
	set("long","�������������������ĵ��ӡ��䵱����֮����Ŵ�ɽ��\n��һ���ɸɾ������಼������\n��������ʮ��ͷ��ͣ�����Ӣ����\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("shen_type", 1);
	set("no_get", 1);
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 2000);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 60000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ren" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi-jian", 100);
	set_skill("taiji-jian", 150);
	set_skill("wudang-jian", 150);
	set_skill("wudang-quan", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");

	create_family("�䵱��", 2, "����");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",2 , ob);
	}
}

void greeting(object ob)
{
	if (((int)ob->query("shen") < 0) &&
		(file_name(environment())=="/d/wudang/jiejianyan"))
	{
		message_vision("�Ŵ�ɽ����ŭ�ݣ���аħ��������˱��ӵ��ˣ���ǿ���䵱����\n�Ŵ�ɽ�Ӹ����£�����һ�ƣ�$Nֻ��Ӳ�ӣ����ӻ���һ�¡��Ŵ�ɽ���ֳ����漴�ݳ���$N�޷��мܣ�����һ����\n\n\n"NOR,ob);
		ob->move("/d/wudang/slxl2");
	}
}

