// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/dabing.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
string ask_me_1(object);

void create()
{
	set_name("�󲡴�ʦ", ({ "dabing dashi", "dabing", "dashi"}));
	set("long", "����һλ��İ�С������ɮ�ˣ��������ƶ��ݡ�\n"
		"��ü��Ŀ��¶����������֮��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",200);
	set("combat_exp", 1000000);
	set("score", 5000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("zhanzhuang-gong", 150);
	set_skill("dodge", 150);
	set_skill("yiwei-dujiang", 220);
// basic skill begin
	set_skill("shaolin-cuff", 220);
	set_skill("luohan-cuff", 220);
	set_skill("weituo-strike", 220);
	set_skill("sanhua-strike", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("nianhua-finger", 220);
	set_skill("boruo-strike", 220);
// basic skill end
// �ƺ͵�
	set_skill("strike", 150);
	set_skill("blade", 150);
	set_skill("cibei-blade", 220);
	set_skill("xiuluo-blade", 220);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("strike", "boruo-strike");
	map_skill("blade", "xiuluo-blade");
	map_skill("parry", "xiuluo-blade");

	prepare_skill("strike", "boruo-strike");
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "roar" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
 	
	set("inquiry", ([
		"����" : (: ask_me_1, "gangchu" :),
		"��" : (: ask_me_1, "chaidao" :),
//		"�ӹ�" : (: ask_me_1, "naogou" :),
//		"����" : (: ask_me_1, "taosuo" :),
	]));
	set("weapon_count", 10);
//	set("tools_count", 5);

	create_family("��������", 19, "����������");
	setup();
	carry_object(WEAPON_DIR+"blade/jiedao")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if ( present(name, this_player()))
		return RANK_D->query_respect(this_player()) +"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";
	if (!(this_player()->query("pass_xin")))
		return "����͵͵�����İɣ����ȥ�ɣ�\n";
	if (query("weapon_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬶����Ѿ������ˡ�";
	ob = new("/d/nanshaolin/obj/" + name);
	ob->move(this_player());
	add("weapon_count", -1);
	message_vision("�󲡸�$Nһ��"+ob->query("name")+"��\n",this_player());
	return "��ȥ�ɡ��ô���Ϊ���з���\n";
}

void attempt_apprentice(object ob)
{
	object me=this_object(); 
	mapping ob_fam, my_fam;
	string name, new_name;
	my_fam =me->query("family");
	name = ob->query("name");

	if(!(ob_fam=ob->query("family")) || ob_fam["family_name"]!="��������")
	{
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if( !(ob->query("pass_xin")) )
	{
		command("say"+RANK_D->query_respect(ob) +"����ô�����ģ�");
		return;
	}
	if( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"��ƶɮ����ҵ���");
		return;
	}
	if( ob->query_skill("force", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"����Ļ����ڹ�����Ҫĥ����ƶɮ��ʱ������Ϊͽ��");
		return;
	}
	if( ob_fam["generation"]==(my_fam["generation"]+1) && name[0..1]=="Ԫ")
	{
		command("say "+ob_fam["master_name"]+"��ͽ����ô�ܵ���������ˣ���������");
		command("recruit "+ob->query("id"));
	}
	if( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		name = ob->query("name");
		new_name = "Ԫ" + name[2..3];
		command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");
		ob->set("name", new_name);
 		ob->set("title", "������ְ��ɮ");
		command("say �����ķ�������"+new_name+"��\n");
		command("say �ӽ��Ժ������������ְ�¸�ɮ�ˣ�����ú����죡\n");
		command("recruit " + ob->query("id"));
	}
	else
		command("say "+RANK_D->query_respect(ob)+"�����Ǵ��ıĳ����ģ��㲻��Խ����ʦ��");
	return;
}
