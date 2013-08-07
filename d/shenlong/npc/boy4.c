// boy4.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"young boy","boy","young"}));
	set("long", "����һ�������̵��ӣ�һϮ���£�����͸��һ��а����\n");
	set("gender", "����");
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
	set_skill("staff", 60);
	set_skill("shenlong-bashi", 40);
	set_skill("shenlong-staff", 30);
	map_skill("staff","shenlong-staff");
	map_skill("parry","shenlong-bashi");
	map_skill("hand","shenlong-bashi");
	prepare_skill("hand","shenlong-bashi");
	set("chat_chance", 3);
	set("chat_msg", ({
		"����˵�����������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n",
		"����˵�����������Ŀ��磬�����ķ���\n",
		"����˵�����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n",
		"����˵�����ҽ̵��ӻ��̶�����ͬ�����á�\n",
		"��������е���������ѵ��ʱ�����ģ������˵У����²��ɣ�\n",
		"�����Ȼ�����е�����־���Ŀɳɳǣ����������ޱ��ף�\n",
		"�����Ȼ�����е����������������������������ǰ˷���\n",
		"�����Ȼ�����е����˷����˳�Ӣ����������ͬ���¹⣡\n",
		"���������е������������ɸ����������룡\n",
	}) );
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIG"������"NOR"����");
	set("party/level", 1);
	create_family("������",3,"����");

	setup();

	carry_object(VEGETABLE_DIR"xionghuang");
	carry_object(__DIR__"obj/gcloth")->wear();
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
