// fang.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"fang duozhu", "fang", "duozhu"}));
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 8);
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("max_qi", 360);
	set("max_jing", 300);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 36);
	
	set("combat_exp", 69000);
	
	set_skill("force", 75); 
	set_skill("huntian-qigong", 72); 
	set_skill("hand", 75); 
	set_skill("suohou-hand", 75); 
	set_skill("dodge", 68); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 70); 
	set_skill("staff", 75); 
	set_skill("fengmo-staff", 75); 
	set_skill("begging", 70); 
	set_skill("training", 60);
	set_skill("strike",70);
	
	set_skill("lianhua-zhang",70);
	set_skill("sunze-youfu",70);
	map_skill("strike","sunze-youfu");
	prepare_skill("strike", "sunze-youfu");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "fengmo-staff");
	map_skill("staff", "fengmo-staff");
	map_skill("dodge", "xiaoyaoyou");
	
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIG"���ʷֶ�"HIY"�˴�����"NOR);
	set("party/level", 8);
	create_family("ؤ��", 11, "����");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("con") < 20 ) return;
	command("say �����Ϊʦ����Ҫ���óԿ��׼�����ú�����ؤ����ӣ�");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
