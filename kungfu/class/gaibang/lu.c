// lu.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
string ask_job();

mapping *names=({
      (["name":                "��Զ��",
       "where" :              "�䵱��",]),  
      (["name":                "������",
       "where" :              "�䵱��",]),  
      (["name":                "Ī����",
       "where" :              "�䵱��",]),
      (["name":                "�����",
       "where" :              "�䵱��",]),
      (["name":                "����Ϫ",
       "where" :              "�䵱��",]), 
      (["name":                "����ͤ",
       "where" :              "�䵱��",]), 
      (["name":                "�������",
       "where" :              "�䵱��",]), 
      (["name":                "ɳͨ��",
       "where" :              "�ƺ��Ĺ�",]), 
      (["name":                "��ͨ��",
       "where" :              "�ƺ��Ĺ�",]), 
      (["name":                "Ǯ�ཡ",
       "where" :              "�ƺ��Ĺ�",]),
      (["name":                "������",
       "where" :              "�ƺ��Ĺ�",]),
      (["name":                "�տն�",
       "where" :              "ؤ��",]),
      (["name":                "������",
       "where" :              "�����ھ�",]),
      (["name":                "����ͬ",
       "where" :              "Ľ������",]),
      (["name":                "�粨��",
       "where" :              "Ľ������",]),
      (["name":                "�˰ٴ�",
       "where" :              "Ľ������",]),
      (["name":                "��Ұ��",
       "where" :              "����",]),
      (["name":                "������",
       "where" :              "������",]),
      (["name":                "����ϼ",
       "where" :              "������",]),
      (["name":                "������",
       "where" :              "������",]),
      (["name":                "������",
       "where" :              "������",]),
      (["name":                "����ʦ̫",
       "where" :              "������",]),
      (["name":                "����ʦ̫",
       "where" :              "������",]),
      (["name":                "����ʦ̫",
       "where" :              "������",]),
       (["name":                "����ʦ̫",
       "where" :              "������",]),
       (["name":                "����ʦ̫",
       "where" :              "������",]),
       (["name":                "����ʦ̫",
       "where" :              "������",]),
       (["name":                "����ʦ̫",
       "where" :              "������",]),
       (["name":                "����ʦ̫",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "������",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "�ۿ�����",
       "where" :              "������",]),
       (["name":                "�ۺ�����",
       "where" :              "������",]),
       (["name":                "�۽�����",
       "where" :              "������",]),
       (["name":                "��ɫ����",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "��������",
       "where" :              "������",]),
       (["name":                "���Ѵ�ʦ",
       "where" :              "������",]),
       (["name":                "�����ʦ",
       "where" :              "������",]),
       (["name":                "������ʦ",
       "where" :              "������",]),
       (["name":                "���ȴ�ʦ",
       "where" :              "������",]),
       (["name":                "��ʹ��ʦ",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "�κ�",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "�ι�",
       "where" :              "������",]),
       (["name":                "��֪",
       "where" :              "������",]),
       (["name":                "��˼",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "��ʶ",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "�μ�",
       "where" :              "������",]),
       (["name":                "�μ�",
       "where" :              "������",]),
       (["name":                "�ξ�",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
       (["name":                "����",
       "where" :              "������",]),
      (["name":                "ʷ��ɽ",
       "where" :              "�����ؽ�",]),
      (["name":                "������",
       "where" :              "����",]),
      (["name":                "�ܵ�",
       "where" :              "����",]),
      (["name":                "˵����",
       "where" :              "����",]),
      (["name":                "����",
       "where" :              "����",]),
      (["name":                "��Ȼ",
       "where" :              "����",]),
     (["name":                "��ң",
       "where" :              "����",]),
     (["name":                "�巨����",
       "where" :              "������",]),
     (["name":                "���ޱ���",
       "where" :              "������",]),
     (["name":                "����",
       "where" :              "ȫ���",]),
     (["name":                "̷����",
       "where" :              "ȫ���",]),
     (["name":                "������",
       "where" :              "ȫ���",]),
     (["name":                "�𴦻�",
       "where" :              "ȫ���",]),
     (["name":                "����һ",
       "where" :              "ȫ���",]),
     (["name":                "�´�ͨ",
       "where" :              "ȫ���",]),
     (["name":                "�ﲻ��",
       "where" :              "ȫ���",]),
     (["name":                "��־ƽ",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־̹",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "��־��",
       "where" :              "ȫ���",]),
     (["name":                "������",
       "where" :              "ȫ���",]),
     (["name":                "�ε·�",
       "where" :              "ȫ���",]),
     (["name":                "�ڵ���",
       "where" :              "ȫ���",]),
       });   
void create()
{
	set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
	set("gender", "����");
	set("age", 45);
	set("long", 
		"³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
		"��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("no_get", 1);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // �����ڹ�
	set_skill("huntian-qigong", 90); // ��������
	set_skill("parry", 90); // �����м�
	set_skill("hand", 95); // �����ַ�
	set_skill("suohou-hand", 95); // �����ַ�
	set_skill("strike", 95); // �����Ʒ�
	set_skill("xianglong-zhang", 90); // ����ʮ����
	set_skill("dodge", 90); // ��������
	set_skill("xiaoyaoyou", 90); // ��ң��
	set_skill("staff", 85); // �����ȷ�
	set_skill("fengmo-staff", 85); // ��ħ�ȷ�
	set_skill("stick", 85); // ��������
	set_skill("dagou-bang", 45); // �򹷰���
	set_skill("begging", 60);
	
	set_skill("lianhua-zhang",85); // ������

	map_skill("force", "huntian-qigong");
	map_skill("parry", "xianglong-zhang");
	map_skill("strike", "xianglong-zhang");
	map_skill("hand", "suohou-hand");
	map_skill("staff", "fengmo-staff");
	map_skill("stick", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("strike", "xianglong-zhang");
	set("inquiry", 
	([
		"����" : (: ask_job :),
		"letter" : (: ask_job :),
	]));
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 18, "�ư���ͷ");

	setup();

	carry_object(__DIR__"obj/jiaohuaji");
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 )
	{
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
		return;
	}
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
		"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
}

string ask_job()
{
	object me;
	object ob;
	int time;
	mapping target, fam;
  	ob=this_player();
	me=this_object();
/*
	if (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
		return RANK_D->query_respect(me) + "��ؤ�������������˻��Ӻ�˵��";
*/
	if (ob->query_temp("gb_songxin")&&present("secret letter", this_player()))
		return ("�㲻���Ѿ��������ŵ������𣿻�����ȥ����\n");
	if (ob->query_condition("gb_songxin") > 1) 
	    { time=1;
	      ob->apply_condition("gb_songxin",time);
	     } 
	if (ob->query_condition("gb_songxin") > 0)
	     {  
		return "������ʱû�и���������ٵ�"+chinese_number(ob->query_condition("gb_songxin"))+"�����ʱ��ɡ�";
	      }
	if (ob->query("combat_exp")>=30000 && !wizardp(ob))
		return "�ҿ�����书�����൱�Ĺ����ˣ��Ͳ���������������ˡ�\n";
	if (ob->query("combat_exp")<100 && !wizardp(ob))
		return "��Ĺ��򻹲����������ſ��Ǻ�Σ�յ��£��ҿɲ��ҽ���������\n";
 
	target = names[random(sizeof(names))];
	
	time = random(10)+(80-2*ob->query("int"));
	if (ob->query("combat_exp")>=10000 && !wizardp(ob))
	    time = time*4/5;
	if (ob->query("combat_exp")>=20000 && !wizardp(ob))
	    time = time*2/3;   
	    
	ob->delete_temp("songxin_ok");
	ob->delete_temp("gb_songxin_late");

	ob->set_temp("gb_songxin",1);
	ob->set_temp("songxin_time",time);
	ob->set_temp("songxin_target_name", target["name"]);
	ob->set_temp("songxin_where", target["where"]);
	ob->delete_temp("songxin_zuji");
	ob->apply_condition("gb_songxin",time);
	switch(random(3))
	{
		case 0:
			message_vision("$N���İ�$n����һ�ԣ�����˵�����������ܺ������͵���"+ob->query_temp("songxin_where")+"��"
"�ġ�"+ob->query_temp("songxin_target_name")+"�����ϡ�\n",me,ob);
			message_vision("$N����$nһ���ܺ���\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);  
			break;
		case 1:
	        message_vision("$N���˵�ͷ��˵���������������з��ţ���ȥ�����͵���"+ob->query_temp("songxin_where")+"��\n�ġ�"+ob->query_temp("songxin_target_name")+"�����ϡ�\n",me,ob);
			message_vision("$N����$nһ���š�\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);
			break;
		case 2:
			message_vision("$N΢΢һЦ���ӻ����ͳ�һ���ţ�˵������Ͻ������͵���"+ob->query_temp("songxin_where")+"��\n�ġ�"+ob->query_temp("songxin_target_name")+"�����ϡ�\n",me,ob);
			message_vision("$N����$nһ���š�\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);
			break;
	}
	
	ob->move(this_player());
	return "·�ϳ���ǿ�˳�û�����С�ġ���";
}
#include "/kungfu/class/gaibang/gaibang.h"
