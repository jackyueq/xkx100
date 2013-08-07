// liang.c 

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"liang zhanglao", "liang", "zhanglao"}));
	set("gender", "����");
	set("age", 55);
	set("long", 
		"��������ؤ�������ã��书��ߵĳ��ϣ��������������Ѿá�\n"
		"ؤ���书������ǿ������������һ�����٣������������ϡ�\n");

	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 120);
	
	set("combat_exp", 100000);
	
	set_skill("force", 90); 
	set_skill("huntian-qigong", 95); 
	set_skill("hand", 85); 
	set_skill("suohou-hand", 90); 
	set_skill("blade", 85); 
	set_skill("liuhe-blade", 90); 
	set_skill("dodge", 93); 
	set_skill("xiaoyaoyou", 90); 
	set_skill("parry", 80); 
	set_skill("staff", 80); 
	set_skill("fengmo-staff", 80); 
	set_skill("begging", 80); 
	set_skill("checking", 90);
	set_skill("training", 80);
	set_skill("strike",85);  // �����Ʒ�
	set_skill("lianhua-zhang",85); // ������
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");
	
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 18, "��������");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}
/*
void init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) &&
		!is_fighting() &&
		file_name(environment(ob))!="/d/city/undertre") 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "ؤ��")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") +
		"��С������˳�����\n", environment(ob), ob);
}
*/
void attempt_apprentice(object ob)
{
	if ((int)ob->query("str") < 25) {
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "����̫�����ƺ�����ѧؤ��Ĺ���");
		return;
	}

	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
