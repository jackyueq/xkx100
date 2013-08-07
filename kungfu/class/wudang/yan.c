// yan.c �����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_yao1();
string ask_yao2();

void create()
{
	set_name("�����", ({ "yu daiyan", "yu" }));
	set("nickname", "�䵱����");
	set("long","������������ĵ��ӡ��䵱����֮��������ҡ�\n��һ���ɸɾ������಼������\n��������ʮ��ͷ��ͣ�˫�Ȳзϣ������������������佣��\n");
	set("gender", "����");
	set("age", 31);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("no_get", "1");
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 50);
	set_skill("tiyunzong", 70);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("taiji-jian", 150);
	set_skill("wudang-quan", 100);
	set_skill("wudang-jian", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
		"����۾���" : (: ask_yao1 :),
		"��ת������" : (: ask_yao2 :),
	]));
	set("yao1_count", 1);
	set("yao2_count", 1);
	create_family("�䵱��", 2, "����");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",2 , ob);
	}
}

void greeting(object ob)
{
	int i;
	if (((int)ob->query_skill("taiji-shengong", 1) == 0))
	{
		message_vision( CYN"ʮ�����Ӷ�$N�����ȵ��������аħ������������佣��\n\n"NOR,ob);
		ob->set("qi",30);
		if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
		else ob->add("combat_exp",0);
		message_vision( CYN"���佣���ʱ��������̨�Ͻ����ݺᣬ��$NΧ�����롣\n"NOR,ob);
		message_vision( CYN"ʮ���ڳ����������$N���ϻ�����ʮ�������ӣ���Ѫ���졣\n"NOR,ob);
		message_vision("����ҾӸ����£�����һ�ư�$N�����̨��\n\n\n"NOR,ob);
		ob->move("/d/wudang/nanyangong");
	}
}

void attempt_apprentice(object me)
{
	command("say " + RANK_D->query_respect(me) + "�����Ǹ������ˣ���ô����ͽ�أ�");
	return;
}

string ask_yao1()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if (ob = present("jujing dan", this_player()))
		return "�����ϲ��Ǵ��ű�������۾�������";
	if (query("yao1_count") < 1)
		return "�������ˣ���������۾����Ѿ������˱��ɵ��ӡ�";
	add("yao1_count", -1);
	ob = new("/clone/medicine/nostrum/jujingdan");
	ob->move(this_player());
	return "�������б�������۾���������ȥ�ɡ�";
}

string ask_yao2()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (ob = present("jieqi wan", this_player()))
		return "�����ϲ��Ǵ��ű��ž�ת�����裿��";
	if (query("yao2_count") < 1)
		return "�������ˣ����ž�ת�������Ѿ������˱��ɵ��ӡ�";
	add("yao2_count", -1);
	ob = new("/clone/medicine/nostrum/jieqiwan");
	ob->move(this_player());
	return "�������б��ž�ת�����裬����ȥ�ɡ�";
}

