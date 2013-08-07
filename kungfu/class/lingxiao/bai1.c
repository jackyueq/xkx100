// Last Modified by winder on Jul. 15 2001
// bai-wanjian.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("����",({"bai wanjian","bai"}));
	set("nickname", HIC"��������"NOR);
	set("gender", "����");
	set("age", 30);
	set("long", 
		"������ѩɽ���������������������ڵĳ��ӣ���\n"
		"��ʦ�ֵܾ��ԡ��������У������־�Ȼ�е����򽣣�\n"
		"�������֮�ߡ�����������������롮�������������\n"
		"��ϳơ�ѩɽ˫�ܡ���\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("per", 30);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 80);

	set("combat_exp", 1500000);
	set("score", 50000);
	set("inquiry", ([
		"������" : "��ү�ӵ�̨������е���",
		"��ү��" : "����ݼ���ү���𣿵����չ���ڣ�����ҳ�ʦ��Ҫ�����ƣ����ܼ�������",
		"����"   : "����ݼ���ү���𣿵����չ���ڣ�����ҳ�ʦ��Ҫ�����ƣ����ܼ�������",
		"����"   : "���������������ر���ֻ��ƾ�������ܽ��������",
	]));
	set("shen_type", 1);

	set("env/wimpy", 60);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.xuehua" :),
		(: perform_action, "sword.wanmei" :),
		(: perform_action, "sword.fengxue" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("force", 120);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 150);
	set_skill("snowstep", 150);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("������", 6, "����");
	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/baihong-jian");
		if ( ob->violate_unique())
		 {
		 	destruct(ob);
		 	ob=new(WEAPON_DIR"changjian");
	 	}
	 	ob->move(this_object());
	 	ob->wield();
	}
	carry_object("/clone/money/gold");
	carry_object(CLOTH_DIR+"bai")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 28)
	{
		command("say ���������ʣ����ܸ���ѧ����");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 60 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɣ�");
		return;
	} 
	if ((int)ob->query_skill("xueshan-sword",1) < 80 )
	{
		command("say ��ı��Ž���̫���ˣ�����������ʦ����߰ɣ�");
		return;
	}
	if ((int)ob->query_skill("sword",1) < 80 )
	{
		command("say ��Ļ�������̫���ˣ���������߻������ɣ�");
		return; 
	}
	if ((int)ob->query("shen") < 20000 )
	{
		command("say ѧ��������������������?"); 
		return;
	} 
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
} 

