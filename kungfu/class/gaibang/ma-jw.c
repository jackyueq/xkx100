// ma-jw.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���Ϊ", ({"ma juwei", "ma", "juwei"}));
	set("gender", "����");
	set("age", 35);
	set("long", 
		"����λ���վ�ǿ��ȴ��Ĭ���Ե�ؤ���ߴ����ӡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 7);
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
	set_skill("blade", 68); 
	set_skill("liuhe-blade", 75); 
	set_skill("dodge", 68); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 70); 
	set_skill("staff", 75); 
	set_skill("begging", 70);
	set_skill("strike",70); 
	
	set_skill("lianhua-zhang",70);
	set_skill("shuanglong-qushui",70);
	map_skill("strike","shuanglong-qushui");
	prepare_skill("strike", "shuanglong-qushui");
	map_skill("force", "huntian-qigong");
	map_skill("blade", "liuhe-blade");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", GRN"�ߴ�����"NOR);
	set("party/level", 7);
	create_family("ؤ��", 19, "����");
	setup();

	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("con") < 20 ) return;
	command("say �����Ϊʦ����Ҫ���óԿ��׼�����ú�����ؤ����ӣ�");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
