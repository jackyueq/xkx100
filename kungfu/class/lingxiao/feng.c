// Npc: /d/lingxiao/npc/feng.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������",({"feng wanli","feng"}));
	set("nickname", HIR"�������"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"���������ǵ��������ӷ�����ǵ����������г������\n"
		"������佣������Ѹ�ݣ����磬���һ𣬵��˸����\n"
		"��������š�����֪Ϊ�Σ�������һֻ�ֱۣ�����ȫ�Ƿ�ŭ\n"
		"�ں�֮ɫ��\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("qi", 2500);
	set("max_qi", 2500);
	set("jiali", 80);

	set("combat_exp", 250000);
	set("shen_type", 1);
	set("score", 50000);

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
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 100);
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

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 25)
	{
		command("say ���������ʣ����ܸ���ѧ����");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 50 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɣ�");
		return;
	} 
	if ((int)ob->query_skill("xueshan-sword",1) < 50 )
	{ 
		command("say ��ı��Ž���̫���ˣ�����������ʦ����߰ɣ�");
		return;
	}
	if ((int)ob->query("shen") < 10000 )
	{
		command("say ѧ��������������������");
		return;
	} 
	if ((int)ob->query_skill("sword",1) < 50 )
	{
		command("say ��Ļ�������̫���ˣ���������߻������ɣ�");
		return; 
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
} 

