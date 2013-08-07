// li-futou.c
// Modified by Venus. Nov.1997

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("�ͷ", ({"li futou", "li", "futou"}));
	set("gender", "����");
	set("class", "beggar");
 	set("beggarlvl", 6);
	set("age", 20);
	set("long",
		"����λؤ���������ӣ������Ǹ���ز�¶�ĸ��֡�\n");
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 27);
	set("max_qi", 250);
	set("max_jing", 220);
	set("neili",300);
	set("max_neili", 300);
	set("jiali",30);
	set("combat_exp", 60000);

	set_skill("force", 60);
	set_skill("huntian-qigong", 60);
	set_skill("blade", 60);
	set_skill("liuhe-blade", 60);
	set_skill("hand", 60);
	set_skill("suohou-hand", 60);
	set_skill("dodge", 60);
	set_skill("xiaoyaoyou", 60);
	set_skill("parry", 60);
	set_skill("begging", 60);
	set_skill("checking", 60);
	set_skill("lianhua-zhang",60);
	set_skill("zhenjing-baili",60);
	set_skill("strike",60);
	map_skill("strike","zhenjing-baili");
	prepare_skill("strike", "zhenjing-baili");
	map_skill("force", "huntian-qigong");
	map_skill("blade", "liuhe-blade");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIY"��������"NOR);
	set("party/level", 6);
	create_family("ؤ��", 19, "����");
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
