// tianlang.c ������
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
string ask_job();

void create()
{
	set_name("������", ({ "tianlang zi", "tianlang", "zi" }));
	set("nickname", "������������");
	set("long", "һ��ò���Һ���ʵʮ�ֽ��������ӡ�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);
	set("di_count", 10);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 30);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 30);
	set_skill("parry", 40);
	set_skill("poison", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("env/wimpy", 60);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "strike.biyan" :),
	}));
	create_family("������", 2, "����");
	set("inquiry", ([
		"������" : "������룬�Ͱ���Ϊʦ��",
		"���޺�" : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�",
		"������" : "����������е���û��ûС�ġ��Ժ�����ɣ�",
		"����"   : (: ask_job :),
		"job"    : (: ask_job :),
	]));
	create_family("������", 2, "����");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "������")
	{
		say("�����Ӷ�"+ob->name()+"������\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1) < 70 || ob->query("shen") > -5000)
	{
		command("say ����������������ҲŲ��������ء�");
		return;
	}
	command("say �ðɣ�������Ļ������е�����ˣ��Ҿ�������ɡ�");
	command("recruit " + ob->query("id"));
}
string ask_job()
{
	object me, ob;
	mapping fam;
	int shen, exp;
	me = this_player();
	fam = (mapping)me->query("family");
	shen = me->query("shen");
	exp=me->query("combat_exp",1); 
 
	if(!fam) return "���ó��������̬�ȹ������β��ȼ������������أ�";
	if (fam["family_name"] != "������" && !me->query_temp("ding_flatter"))
		return "������ɵ�̬�ȿ���ȥ��̫��������";
	if(exp<100000) return "�����������ټӰ��������ɡ�";
	if(exp>=250000)
		return "�������������Ҳ�̫�������ȥ������ʦ��ʨ���Ӱɡ�";
	if(me->query_condition("wait_xx_task"))
		return "�ϴθ����ˣ������͵ȵȰɡ�";     
	if(interactive(me) && me->query_temp("xx_job"))
		return "����ô�������﷢����";
	if(interactive(me) && me->query_condition("wait_xx_task"))  
		return "�����������黹�ã���������Ϊ�����ǡ�";
	if(query("di_count") < 1)  
		return "�����������黹�ã�������������ˡ�";
	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", YEL "����̵�" NOR);
	ob->set("long", YEL"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���ƣ���Ө�ɰ���\n" NOR);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "������")
	me->set_temp("apply/short", ({YEL"��������� "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N�ó�һֻ���ƶ̵ѣ�����$n��\n", this_object(), me);
	return "����������鲻�ѣ����Ҫ���Ϊ�����˼ҷ��ǲ��ǣ�\n";    
}

