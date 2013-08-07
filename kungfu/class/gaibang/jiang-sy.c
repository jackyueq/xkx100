// jiang-shangyou.c
// Modified by Venus Nov.1997

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("������", ({"jiang shangyou", "jiang", "shangyou"}));
	set("gender", "����");
	set("age", 19);
	set("long",
		"����λؤ��������ӣ������Ǹ�Ӣ�����\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 5);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 27);
	set("max_qi", 220);
	set("max_jing", 200);
	set("neili",250);
	set("max_neili", 250);
	set("jiali",25);
	set("combat_exp", 50000);
	set_skill("force", 50);
	set_skill("huntian-qigong", 50);
	set_skill("hand", 50);
	set_skill("suohou-hand", 50);
	set_skill("dodge", 50);
	set_skill("xiaoyaoyou", 50);
	set_skill("parry", 50);
	set_skill("begging", 50);
	set_skill("checking", 50);
	set_skill("lianhua-zhang",40);
	set_skill("lishe-dachuan",40);
	set_skill("strike",40);
	map_skill("strike","lishe-dachuan");
	prepare_skill("strike", "lishe-dachuan");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", YEL"�������"NOR);
	set("party/level", 5);
	create_family("ؤ��", 20, "����");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
}
										
void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "����") return;
	command("say �ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
