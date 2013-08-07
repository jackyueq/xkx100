// deng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�˰ٴ�", ({ "deng baichuan", "deng","baichuan" }));
	set("title", "����Ľ�� "HIG"����ׯ��"NOR );
	set("long", "����һ����ʿ��������������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("blade", 120);
	set_skill("finger", 120);
	set_skill("strike", 120);
	set_skill("literate", 100);
	set_skill("murong-sword", 180);
	set_skill("murong-blade", 180);
	set_skill("canhe-finger", 180);
	set_skill("xingyi-strike", 180);
	set_skill("shenyuan-gong", 120);
	set_skill("yanling-shenfa", 180);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({		
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry",([
		"������" : "ֻ��������������ǹ��ӣ�Ҳ��֪�����������ˣ�\n",
		"��Ľ��" : "�Ҽҹ��Ӻ�ؤ���ǰ����������ϳơ���Ľ�ݱ��Ƿ塱��\n",
		"Ľ�ݸ�"   : "��������Ҳ�������������Ҽҹ��ӣ�\n",
		"������"   : "���ǹ���ү�ľ��裬����ɽׯ��ׯ����\n",
		"�˰ٴ�"   : "�Ǿ����ҡ��������£�\n",
		"��ұǬ"   : "��ұ���ܰ��Ÿ봫��һ���룬��û�����˶��ö��ˡ�\n",
		"����ͬ"   : "�������̧���ˣ�����������Ǳ���ĺá�\n",
		"�粨��"   : "���ĵ����Ǻ�ˬ�ˣ����Ӳ����˼ƽ�ʲô��\n",
	]) );
	create_family("����Ľ��", 33, "����");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say ��λ" + RANK_D->query_respect(ob) +
			"����Ľ�ݼҸ�������ΪҪ�£�����־���ᣬ��Ե���š�");
		return;
	}
	if ((int)ob->query_skill("shenyuan-gong", 1) < 50)
	{
		command("say ����Ľ�ݼ��书�����ڹ�Ϊ������");
		command("say "+RANK_D->query_respect(ob)+"��Ӧ�ö��Ŭ����");
		return;
	}
	command("say �ð��Ҿ�����Ϊͽ�ɡ�");
	command("recruit " + ob->query("id"));
}
