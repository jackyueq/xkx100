// kuai-huosan.c
// Modified by Venus Nov.1997

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("�����", ({"kuai huosan", "kuai", "huosan"}));
	set("gender", "����");
	set("age", 18);
	set("long",
		"����λؤ���Ĵ����ӣ������Ǹ����е�������ˡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 4);
	set("str", 22);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 180);
	set("max_jing", 190);
	set("neili",200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 32000);
	set_skill("force", 45);
	set_skill("huntian-qigong", 45);
	set_skill("blade", 45);
	set_skill("liuhe-blade", 45);
	set_skill("hand", 45);
	set_skill("suohou-hand", 45);
	set_skill("dodge", 45);
	set_skill("xiaoyaoyou", 45);
	set_skill("parry", 45);
	set_skill("begging", 45);
	set_skill("checking", 45);
	set_skill("lianhua-zhang",45);
	set_skill("hongjian-yulu",45);
	set_skill("strike",45);
	map_skill("strike","hongjian-yulu");
	prepare_skill("strike", "hongjian-yulu");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "liuhe-blade");
	map_skill("blade", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIM"�Ĵ�����"NOR);
	set("party/level", 4);
	create_family("ؤ��", 20, "����");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}
void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "����") return;
	command("say �ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
