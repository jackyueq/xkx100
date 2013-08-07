// Npc: /kungfu/class/nanshaolin/fangtong.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("��ͨ", ({ "fang tong", "fang", "tong"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("nickname", "֪��ɮ");
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
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 30);
	set_skill("zhanzhuang-gong", 30);
	set_skill("dodge", 30);
	set_skill("yiwei-dujiang", 30);
	set_skill("cuff", 30);
	set_skill("shaolin-cuff", 30);
	set_skill("leg", 30);
	set_skill("shaolin-leg", 30);
	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "shaolin-cuff");
	map_skill("leg", "shaolin-leg");
	map_skill("parry", "shaolin-cuff");
	prepare_skill("cuff", "shaolin-cuff");
	prepare_skill("leg", "shaolin-leg");

	create_family("��������", 21, "����");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

int accept_object(object who, object ob,object me)
{
	mapping fam; 
	me=this_object();
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
	{
		command("hehe "+who->query("id"));
		command("say ����Ҷ�����ʲô��ͼ����");
		return 0;
	}
	if(!who->query_temp("lunzhi"))
	{
		command("say ��������������ģ���ֵ����õ�����ʦ������");
		return 0;
	}
	if(ob->query("name")=="��ֵ��")
	{
		command( "say �ðɣ����Ȼ�д���ʦ�����ƣ�����������������һ�������ɡ�");
//		who->apply_condition("sl_lunzhi",random(5)+15);
		who->apply_condition("sl_lunzhi", 2);
		who->set_temp("lunzhied",1);
		return 1;
	}
	return 1;
}
#include "/kungfu/class/nanshaolin/fang.h";

