// li-sh.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({"li sheng", "li", "sheng"}));
	set("gender", "����");
	set("age", 38);
	set("long", 
		"����λ���Ը�ֱ����������ؤ��˴����ӡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 8);
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 390);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	
	set("combat_exp", 79000);
	
	set_skill("force", 81);
	set_skill("huntian-qigong", 82);
	set_skill("hand", 85);
	set_skill("suohou-hand", 75);
	set_skill("strike", 85);
	set_skill("xianglong-zhang", 75);
	set_skill("dodge", 80);
	set_skill("xiaoyaoyou", 82);
	set_skill("parry", 82);
	set_skill("staff", 80);
	set_skill("begging", 70);
	set_skill("training", 70);
	
	set_skill("lianhua-zhang",70);
	set_skill("diyang-chufan",70);
	map_skill("strike","diyang-chufan");
	prepare_skill("strike", "diyang-chufan");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("strike", "xianglong-zhang");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIG"�˴�����"NOR);
	set("party/level", 8);
	create_family("ؤ��", 19, "����");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("shen") < 0 ) return;
	command("say �ã���������һ��һ���˲�����ͽ�ܣ��һ�ϲ���������أ�");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"