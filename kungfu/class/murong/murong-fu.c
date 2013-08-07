// murong-fu.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("Ľ�ݸ�", ({ "murong fu", "murong","fu" }));
	set("nickname", HIG"��Ľ��"NOR);
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
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("san_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("strike", 200);
	set_skill("finger", 200);
	set_skill("murong-sword", 300);
	set_skill("murong-blade", 300);
	set_skill("canhe-finger", 300);
	set_skill("xingyi-strike", 300);
	set_skill("shenyuan-gong", 200);
	set_skill("yanling-shenfa", 300);
	set_skill("douzhuan-xingyi", 150);
	map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("parry", "douzhuan-xingyi");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("inquiry",([
		"������"    : "�������ұ��ã���һֱ������С���ÿ�����\n",
		"��Ľ��"    : "����Ľ�ݱ��Ƿ塱�����ǽ����ϵ�����̧���ˣ�\n",
		"Ľ�ݸ�"    : "���Ǽ������������ǣ�\n",
		"�˰ٴ�"    : "���ʵ˴�簡�����������ׯ���ء�\n",
		"��ұǬ"    : "��ұ������Ÿ봫��һ���룬��û�����˶��ö��ˡ�\n",
		"����ͬ"    : "�������̧���ˣ�����������Ǳ���ĺá�\n",
		"�粨��"    : "���ĸ����Ǻ�ˬ�ˣ����Ӳ����˼ƽ�ʲô��\n",
		"�粨��"    : "���ĸ����Ǻ�ˬ�ˣ����Ӳ����˼ƽ�ʲô��\n",
		"��¶����ɢ": (: ask_me :),
	]) );
	set("no_get",1);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: perform_action, "parry.xingyi" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("����Ľ��",33, "����");
 	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say ��λ" + RANK_D->query_respect(ob) +
			"����Ľ�ݼҸ�������ΪҪ�£�����־���ᣬ��Ե���š�");
		return;
	}
	if ((int)ob->query_skill("shenyuan-gong", 1) < 100)
	{
		command("say ����Ľ�ݼ��书�����ڹ�Ϊ������");
		command("say "+RANK_D->query_respect(ob)+"��Ӧ�ö��Ŭ����");
		return;
	}
	command("say �ð��Ҿ�����Ϊͽ�ɡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("san_count") < 1)
		return "�������ˣ����ɵ���¶����ɢ���ڴ˴���";
	add("san_count", -1);
	ob = new("/clone/medicine/nostrum/yulusan");
	ob->move(this_player());
	return "�ðɣ�����¶����ɢ����ȥ�ɡ�";
}
