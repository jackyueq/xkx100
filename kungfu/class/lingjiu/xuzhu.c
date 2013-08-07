// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("����", ({ "xu zhu", "xu", "zhu" }));
	set("long",
		"����һ����ʮ������������ˣ�Ũü���ۣ����ı��ӱ�ƽ��������ò
��Ϊ��ª����һ���������µĳ��ۣ���ʹ�����Լ��־���
��������ɽͯ�ѵľ������ˡ�\n");
	set("title", "���չ��ڶ���������");
	set("gender", "����");
	set("age", 26);
	set("nickname", HIR "����" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 20000);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike", 200);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("tianyu-qijian", 300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 200);
	set_skill("beiming-shengong",200);
	set_skill("hunyuan-yiqi",100);
	set_skill("shaolin-shenfa",100);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("sword", "tianyu-qijian");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.san" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );	
	set("no_teach", ([
		"beiming-shengong" : "����������ʦ��ע�������ڵģ�������ô�̸��㣿",
                "hunyuan-yiqi"     : "���⡭�ⶫ���Ҷ�ûѧ�á�",
                "shaolin-shenfa"   : "��������š��һ��ǽ��㱾�ŵ��Ṧ���ˡ�",
	]));
	create_family("��ң��",2,"����");
	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/food/jiudai");
	add_money("silver",50);
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
	{
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
	}  
	if ((string)ob->query("gender")=="Ů��")
	{
  	      command("nod");
  	      command("say ����Сɮ�����¾������㣬�Ժ���Ҫ�������¡�");
  	      command("say ���⣬�Ժ��������������µĴ�ʦ����ǧ���ܺ�����Ϊ�ѡ�");
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("��������㿴�˰���,˵���������²������������ҵ������?��\n",ob);
		return;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		ob->set("title","���չ�����������");
	}
}