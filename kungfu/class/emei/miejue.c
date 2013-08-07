// miejue.c ���ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
	set_name("���ʦ̫", ({ "miejue shitai","miejue","shitai"}));
	set("long", "���׼��շ����Ƕ����ɵĵ��������ӣ����ζ����������ˡ�\n");
	set("gender", "Ů��");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 100000);
	set("class", "bonze");
	set("no_get",1);
	set("inquiry",([
		"���" : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
		"����" : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
		"����" : (: ask_for_quit :),
	]));

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",130);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 3000000);
	set("score", 1000);
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
//	map_skill("magic","bashi-shentong");
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
	create_family("������", 3, "����");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}

void init()
{
	object ob;
	mapping myfam;

	::init();
	if (interactive(ob=this_player()) && ob->query("family"))
	{
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "������")&&(!ob->query_skill("linji-zhuang",1))&&(ob->query("combat_exp")>500000))
       		{
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + ob->query("id"));
        	}
	}
    	add_action("do_qiecuo","qiecuo");
//    	add_action("do_kneel", "kneel");

}

void attempt_apprentice(object ob)
{
	mapping ob_fam;
	mapping my_fam = ob->query("family");

	string name, new_name;
	name = ob->query("name");

	if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	switch (random(2))
	{
		case 1: break;
		default:
			if ((string)ob->query("class")!="bonze" )
			{
				command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
				return;
			}
			else
			{
				command ("say �����ӷ�ƶ�᲻�յ��ӡ�");
				return;
			}
	}
	if ((int)ob->query_skill("mahayana",1)<90 ||
		(int)ob->query_skill("linji-zhuang",1)<90)
	{
		command("say �㱾�ŵĹ�����Ϊ��̫�͡�");
		return;
	}
	if ((int)ob->query("shen") < 50000)
	{
		command("say "+RANK_D->query_respect(ob)+"����������֮�»����Ĳ�����");
		return;
	}
	if ((string)ob->query("class")=="bonze" )
	{
		name = ob->query("name");
		new_name = "��" + name[2..3];
		ob->set("name", new_name);
		command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ���Ϊ���ҵ��Ĵ�����!");
	}

	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
	command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
	command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
	object me = this_player();
	mapping myfam;

	myfam = (mapping)me->query("family");
	if (!myfam || (myfam["family_name"] != "������")) 
		return ("��Ͷ���û��ԨԴ��ƶ�᲻�Ҹ��㻹�ס�\n");
	if( (string)me->query("class")!="bonze" )
		return "�����ӷ𣡳����˲���ڿ����Ѿ����׼����ˡ�\n";
	if (!me->query_temp("pending/quit_bonze") && random(5)!=1)
		{
			command("heng");
   	 return "��úõĸ��Ұ����������Ժ�����ħ�������������Ӳ�������";
		}
		me->set_temp("pending/quit_bonze", 1);
		command ("say �����ӷ����գ����գ���һ��Ҫ���ף���Ҳ��������\n");
		command ("say �ҽ���ȥ�㲿���书�������(kneel)������\n");
		add_action("do_kneel","kneel");
		return "�����Ը���׵ģ��Ͱ����ڴ������ɡ�";
}

int do_kneel(string arg)
{
		object me=this_player();
		object master=this_object();
		command("say ��Ȼ�����������Ҷ���������ƶ��ͳ�ȫ�㡣");
		command("say �ӽ����󣬶�����Ҳû��"+me->query("name")+"������");
		me->delete_temp("pending/quit_bonze");
		me->delete_skill("linji-zhuang");
		me->delete_skill("mahayana");
		me->delete("class");
		me->set("detach/emei",1);
		command("expell " + me->query("id"));
//	me->delete("betrayer");
		return 1;
}

