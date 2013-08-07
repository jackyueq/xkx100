// zhang.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("�ŵ���", ({ "zhang danyue", "zhang"}));
	set("long", "����һ�����´󺺣���ɫ��䣬���ӷ������ƺ��־��Ѽ���\n" );
	set("gender", "����");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",3000);
	set("qi",3000);
	set("max_jing",1000);
	set("jing",1000);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("leg", 85);
	set_skill("hook", 85);
	set_skill("yixingbu", 85);
	set_skill("jueming-leg", 85);
	set_skill("dulong-dafa", 90);
	set_skill("ruyi-hook", 85);
	set_skill("parry", 70);
	set_skill("literate", 70);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("leg", "jueming-leg");
	map_skill("hook", "ruyi-hook");
	map_skill("parry", "jueming-leg");
	prepare_skill("leg", "jueming-leg");
	set("env/wimpy", 60);
	set("party/party_name", HIY"������"NOR);
	set("party/rank", BLK"������"NOR"����ʹ");
	set("party/level", 2);
	create_family("������", 2, "����");

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
	]) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 10);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_join","join");
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))	  
		{
			set("combat_exp",100000);
			set("qi",100);
			set("jing",100);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	command("say ���߿������ң�");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
