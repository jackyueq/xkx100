// guo.c ����
// Modified by Winder Jul.2000
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
	set_name("����", ({ "guo xiang","guo","xiang"}));
	set("long",
"��ʮ�˾�����ͣ�����������������һͷ��¿�����������С�
�������̽����������з糾֮ɫ������Զ���Ѿã��ػ��绨����
��ϲ������֮�꣬������ɫ��ȴ�����а����⣬���ǳ�˼Ϯ�ˣ�
ü�����ϣ��޼ƻرܡ����չ�������һ�����֣��˴���������Ů
�����صĴ�Ů��������һ¿һ����ֻ�����Σ���ǲ���г��ơ�\n"); 
	set("gender", "Ů��");
	set("nickname", "С��а");
	set("age", 18);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 100000);
	set("class", "bonze");
	set("env/wimpy", 60);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set_temp("is_riding", HIC"��¿"NOR);
	set("combat_exp", 3000000);
	set("score", 1000);
	set("chat_chance", 10);
	set("chat_msg", ({
		"��������������������䣬���Ǻ��ֱ������������\n",
		"������������������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
		"�������������������Ȥ�����࣬���и��гն�Ů����\n",
		"�����������������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
		"������������������·����į������ġ���������ƽ������\n",
		"����������������л�Щ��ർ���ɽ��������ꡣ��\n",
		"�����������������Ҳ�ʣ�δ���룬ݺ�����Ӿ��������\n",
		"���������������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
		(: random_move :)
	}) );

	set_skill("persuading", 150);
	set_skill("throwing", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("literate", 100);
	set_skill("mahayana", 200);
	set_skill("buddhism", 200);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("huifeng-jian", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang", 200);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("blade","yanxing-dao");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
//		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
	create_family("������", 1, "������");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	carry_object(__DIR__"obj/donkey");
}

void attempt_apprentice(object ob)
{
	mapping ob_fam;
	mapping my_fam = ob->query("family");
	string name, new_name;
	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if ((string)ob->query("class")!="bonze" )
	{
		command ("say �Ҳ����׼ҵ��ӡ�");
		return;
	}
	if ((int)ob->query_skill("mahayana",1)<150||
		(int)ob->query_skill("linji-zhuang",1)<150)
	{
		command("say �㱾�ŵĹ�����Ϊ��̫�͡�");
		return;
	}
	if ((int)ob->query("shen") < 500000)
	{
		command("say "+RANK_D->query_respect(ob)+"����������֮�»����Ĳ�����");
		return;
	}
	if ((string)ob->query("class")=="bonze" )
	{
		name = ob->query("name");
		new_name = "��" + name[2..3];
		ob->set("name", new_name);
		command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ���Ϊ���ҵ���������!");
	}
	command("recruit " + ob->query("id"));
}

