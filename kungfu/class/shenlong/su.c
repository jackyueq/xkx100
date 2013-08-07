// su.c ����

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

int ask_tuijiao();
void create()
{
	set_name("����", ({ "su quan", "su" }));
	set("long","��ò�ٸ�����ģ��������ʮ��������ͣ�΢΢һЦ����̬�����������ޱȡ�\n");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 400000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 150);
	set_skill("dodge", 180);
	set_skill("yixingbu", 250);
	set_skill("leg", 150);
	set_skill("strike", 180);
	set_skill("jueming-leg", 220);
	set_skill("huagu-mianzhang", 250);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("meiren-sanzhao", 220);
	set_skill("literate", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("leg", "jueming-leg");
	map_skill("parry", "meiren-sanzhao");
	map_skill("sword", "meiren-sanzhao");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("leg", "jueming-leg");
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIR"��������"NOR );
	set("party/level", 3);
	create_family("������", 2, "����");

	set("inquiry", ([
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"�˽�"   : (: ask_tuijiao :),
		"rujiao" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"tuijiao": (: ask_tuijiao :),
	]));
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat ƾ��������ͣ�Ҳ��������ͷ�϶�����\n") :),
		(: command("say ���ò��ͷ�����������\n") :),		
		(: perform_action, "strike.hua" :),
		(: perform_action, "strike.baigu" :),
		(: perform_action, "sword.fengzi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
       
	setup();
	carry_object("/d/shenlong/npc/obj/ycloth")->wear();
	carry_object(__DIR__"obj/duanjian")->wield();
	add_money("silver", 50);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))	  
		{
			set("combat_exp",500000);
			set("qi",10);
			set("jing",10);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "������" NOR ) {
		command("say �㲻�Ǳ��̽��ڣ�������������");
		return;
	}
	if ((int)ob->query_skill("dulong-dafa",1) < 60 ) {
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɣ�");
		return;
	}
	if ((int)ob->query("shen") > -10000  ) {
	command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}

int ask_tuijiao()
{
	object ob;
	ob=this_player();

	if(ob->query("party/party_name") != HIY "������" NOR )
	{
	message_vision("����ݸ��һЦ����$N˵�����㻹û�������������أ������˽̣�\n",ob);
		return 1;
	}
	if(ob->query("family/family_name") == "������" )
	{
		message_vision("��������������$N˵�������Ѿ������������ӣ�������˽̣�\n", ob);
		return 1;
	}
	command("look "+ob->query("id"));
	command("sigh ");
	command("nod ");
	command("say �����㲻Ҫײ�������ϣ�");
	ob->delete("party");
	ob->delete("rank");
	ob->delete("level");
	return 1;
}

