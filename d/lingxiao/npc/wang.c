// Npc: /d/lingxiao/npc/wang.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������",({"wang wanren","wang"}));
	set("gender", "����");
	set("age", 20);
	set("long", 
	       "���������ǵ���������������ר�Ÿ�����������ŵĵ�����ɽ��\n"
	       "�������������нܳ����ӣ�ֻ�Ǻþ�̰�����ű�������������\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("max_jing", 1000);
	set("jing", 1000);
	set("max_qi", 1500);
	set("qi", 1500);
	set("jiali", 50);

	set("combat_exp", 200000);
	set("chat_chance", 10);
	set("chat_msg", ({
"��������˸����磬̾��һ���������ط����湻��ģ�Ҫ���е�ƺȾ�ů�Ͷ��ˡ�\n", 
"������˵������Ҫ�ܸ��ҵ�ƣ��Ҿ�������ܵ�ȥ��ɽ��С��������ġ�\n", 
	}) );
	set("inquiry", ([
		"����"   : "����ֻ�������������Ӳ����ߵġ�",
	]));
	set("shen_type", 0);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 120);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 120);


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
	command("say ���ǲ���ͽ�����������ʦ���Ǻ��ˡ�");
}

int accept_object(object me, object ob)
{
	if ((string)ob->query("name")!="ţƤ�ƴ�")
	{
		command("say ������������ʲô��");
		return 1;
	}
	else
	{
		command("say ��λ"+RANK_D->query_respect(me) + "��̫���ˣ�\n��л�ˣ������������ܵ�ȥ��������ǧ��Ҫ˵���ҷ����ȥ��Ŷ��\n");
		me->move("/d/lingxiao/andao");
		return 1;
	}
}

