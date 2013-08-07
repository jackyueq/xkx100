// qiu-wanjia.c
// Modified by Venus Nov.1997

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
void create()								   
{
	set_name("�����", ({"qiu wanjia", "qiu", "wanjia"}));
	set("gender", "����");
	set("age", 16);
	set("long",
		"����λ��Ʀ�Ƶ�ؤ��������ӣ������Ǹ��Եÿ���С��Ʀ��\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 2);
	set("str", 19);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 130);
	set("max_jing", 130);
	set("neili", 170);
	set("max_neili", 170);
	set("jiali", 10);
	set("combat_exp", 8000);
	set_skill("force", 35);
	set_skill("huntian-qigong", 35);
	set_skill("hand", 35);
	set_skill("suohou-hand", 35);
	set_skill("dodge", 35);
	set_skill("xiaoyaoyou", 35);
	set_skill("parry", 35);
	set_skill("begging", 35);
	set_skill("checking", 35);
	set_skill("strike",35);
	set_skill("lianhua-zhang",35);
	set_skill("feilong-zaitian",35);
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike","feilong-zaitian");
	prepare_skill("strike", "feilong-zaitian");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIB"��������"NOR);
	set("party/level", 2);
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
