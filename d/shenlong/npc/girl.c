// girl.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��Ů", ({"young girl","girl","young"}));
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
	map_skill("sword","meiren-sanzhao");
	map_skill("parry","shenlong-bashi");
	map_skill("hand","shenlong-bashi");
	prepare_skill("hand","shenlong-bashi");
	set("chat_chance", 3);
	set("chat_msg", ({
		"��Ů˵�����������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n",
		"��Ů˵�����������Ŀ��磬�����ķ���\n",
		"��Ů˵�����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n",
		"��Ů˵�����ҽ̵��ӻ��̶�����ͬ�����á�\n",
		"��Ů�����е���������ѵ��ʱ�����ģ������˵У����²��ɣ�\n",
		"��Ů��Ȼ�����е�����־���Ŀɳɳǣ����������ޱ��ף�\n",
		"��Ů��Ȼ�����е����������������������������ǰ˷���\n",
		"��Ů��Ȼ�����е����˷����˳�Ӣ����������ͬ���¹⣡\n",
		"��Ů�����е������������ɸ����������룡\n",
	}) );
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIR"������"NOR"����");
	set("party/level", 1);
	create_family("������",3,"����");

	setup();
	switch( random(5) )
	{
		case 0: carry_object(WEAPON_DIR"sword/houjian")->wield();
			break;
		case 1: carry_object(WEAPON_DIR"sword/changjian")->wield();
			break;
		case 2: carry_object(WEAPON_DIR"sword/duanjian")->wield();
			break;
		case 3: carry_object(WEAPON_DIR"sword/kuojian")->wield();
			break;
		case 4: carry_object(WEAPON_DIR"sword/xijian")->wield();
			break;
	}
	carry_object(VEGETABLE_DIR"xionghuang");
	carry_object(__DIR__"obj/rcloth")->wear();
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
