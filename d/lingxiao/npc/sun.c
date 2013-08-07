// Npc: /d/lingxiao/npc/sun.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������",({"sun wannian","sun"}));
	set("gender", "����");
	set("age", 20);
	set("long", 
		"���������ǵ��������������꣬�����ͷ��Ŀ��\n"
		"��ΪƷ�в��ˣ�����������˼����\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("qi", 800);
	set("max_qi", 800);

	set("combat_exp", 50000);
	set("shen_type", -1);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 60);
	set_skill("snow-strike", 60);
	set_skill("snowstep", 60);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("������", 6, "����");
	setup();
	carry_object(CLOTH_DIR+"bai")->wear();
}

