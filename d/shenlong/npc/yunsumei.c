// yunsumei.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����÷", ({"yun sumei", "yun"}));
	set("long", "����һ��������Ů���ӣ�һϮ���£�������Ϊ�ɰ���\n");

	set("gender", "Ů��");
	set("attitude", "peaceful");

	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 20000+random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("hand", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shenlong-bashi", 40);
	set_skill("meiren-sanzhao", 30);
	map_skill("parry","shenlong-bashi");
	map_skill("hand","shenlong-bashi");
	map_skill("sword","meiren-sanzhao");
	prepare_skill("hand","shenlong-bashi");
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIR"������"NOR"����");
	set("party/level", 1);
	create_family("������",3,"����");

	setup();
	carry_object(VEGETABLE_DIR"xionghuang");
	carry_object(WEAPON_DIR"sword/duanjian")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	add_money("silver",5);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
		unconcious();
	}
	return;
}
