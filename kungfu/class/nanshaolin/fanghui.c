// Npc: /kungfu/class/nanshaolin/fanghui.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
#include <ansi.h>;
inherit NPC;
string ask_job();

void create()
{
	set_name("����", ({ "fang hui", "fang", "hui"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("nickname", "��ͷ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("qianye-hand", 50);
	set_skill("strike", 50);
	set_skill("weituo-strike", 50);
	set_skill("blade", 50);
	set_skill("cibei-blade", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "qianye-hand");
	map_skill("strike", "weituo-strike");
	map_skill("blade", "cibei-blade");
	map_skill("parry", "cibei-blade");
	prepare_skill("hand", "qianye-hand");
	prepare_skill("strike", "weituo-strike");

	set("inquiry", ([
		"�ֲ�" : "�����ֲ˽��඼�������ӵģ���ĦԺ����Ҳ����ˣ�\n",
		"����" : (: ask_job :),
	]) );
	create_family("��������", 21, "����");
	setup();
	carry_object(WEAPON_DIR+"blade/jiedao")->wield();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("job_name")!="�˵��ֲ�") return; 
	if(!(ob->query_temp("job_name")!="�˵��ֲ�"))
	{
		command("stare "+ob->query("id"));
		command("say " +RANK_D->query_rude(ob)+"���㻹������������(jiao ��)����ʲô����\n");
	}
}
string ask_job()
{
	object ob = this_player();

	if (ob->query("combat_exp")>=30000)
		return ("���Ѿ����˻����ˣ�û��Ҫ������������ˡ�\n");
	if ((string)ob->query("family/family_name") != "��������")
		return ("�������ֵ��Ӳ����칤����");
	if (ob->query_temp("job_name"))
		return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
	ob->set_temp("job_name","�˵��ֲ�");
		return "����Ҫʲô���ɣ���Ͱ��ҽ���"HIR"(jiao ��)"HIC"�ɡ�";
}
#include "/kungfu/class/nanshaolin/fang.h";

