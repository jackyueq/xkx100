// yu-hx.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({"yu hongxing", "yu", "hongxing"}));
	set("gender", "����");
	set("nickname", "С����");
	set("age", 30);
	set("long", 
		"����λЦ���е�ؤ���ߴ����ӣ����Զ��ǣ����С���á�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("beggarlvl", 7);
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 420);
	set("max_jing", 330);
	set("neili", 780);
	set("max_neili", 780);
	set("jiali", 42);
	
	set("combat_exp", 82000);
	
	set_skill("force", 78); 
	set_skill("huntian-qigong", 76); 
	set_skill("hand", 78); 
	set_skill("suohou-hand", 80); 
	set_skill("blade", 78); 
	set_skill("liuhe-blade", 80); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 82); 
	set_skill("parry", 81); 
	set_skill("begging", 80); 
	set_skill("stealing", 90); 
	set_skill("checking", 70); 
	set_skill("strike",70);
	
	set_skill("lianhua-zhang",70);
	set_skill("shicheng-liulong",70);
	map_skill("strike","shicheng-liulong");
	prepare_skill("strike", "shicheng-liulong");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");
	
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", GRN"�ߴ�����"NOR);
	set("party/level", 7);
	create_family("ؤ��", 19, "����");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("int") < 25 ) return;
	command("say �����������Ϊ����ֻ���߹������˼Һ��Ҳ��ر���Щ����ͽ����");
	command("say ��Ҷ�ҪΪ��Զ���밡��");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
