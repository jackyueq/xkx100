// zuo-qu.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ȫ", ({"zuo quan", "zuo", "quan"}));
	set("gender", "����");
	set("age", 35);
	set("long", 
		"����λ��ˬ�󷽵�ؤ���ߴ����ӣ������Ǹ����غ��ܡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 7);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("max_qi", 360);
	set("max_jing", 300);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 36);
	
	set("combat_exp", 68000);
	
	set_skill("force", 73); 
	set_skill("huntian-qigong", 70); 
	set_skill("hand", 70); 
	set_skill("suohou-hand", 73); 
	set_skill("blade", 70); 
	set_skill("liuhe-blade", 73); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 71); 
	set_skill("parry", 70); 
	set_skill("begging", 50); 
	set_skill("checking", 50);
	set_skill("strike",70); 
	
	set_skill("lianhua-zhang",70);
	set_skill("miyun-buyu",70);
	map_skill("strike","miyun-buyu");
	prepare_skill("strike", "miyun-buyu");
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
}

void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "����") return;
	command("say �ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
