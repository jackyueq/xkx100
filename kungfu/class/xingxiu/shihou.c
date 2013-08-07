// shihou.c ʨ����
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
string ask_job();
void create()
{
	set_name("ʨ����", ({ "shihou zi", "shihou", "zi" }));
	set("nickname", "�����ɶ�����");
	set("long","����ʮ���꣬˫���ϸ�����һֻ���λεĻƴ󻷣�ʨ�����ڣ���ò��
Ϊ�׺ݹ��졣һ����֪����������ʿ��\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 30000);
	set("di_count", 10);

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 60);
	set_skill("strike", 70);
	set_skill("chousui-zhang", 40);
	set_skill("claw", 70);
	set_skill("sanyin-wugongzhao", 40);
	set_skill("parry", 60);
	set_skill("poison", 60);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 50);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
	}));
	create_family("������", 2, "����");
	set("inquiry", ([
		"������" : "������룬�Ͱ���Ϊʦ��",
		"���޺�" : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�",
		"������" : "����������е���û��ûС�ġ��Ժ�����ɣ�", 
		"����"   : (: ask_job :), 
		"job"    : (: ask_job :), 
	]));

	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
	carry_object("/d/xingxiu/obj/fire");
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "������")
	{
		say("ʨ���Ӷ�"+ob->name()+"������\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1) < 45 || ob->query("shen") > -500)
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

	if(!fam)
		return "���ó��������̬�ȹ������β��ȼ������������أ�";
	if(fam["family_name"] != "������" && !me->query_temp("ding_flatter"))
		return "������ɵ�̬�ȿ���ȥ��̫��������";
	if(exp<250000)
		return "�����������ټӰ��������ɡ�";
	if(exp>=500000)
		return "�������������Ҳ�̫�������ȥ������ʦ��ժ���Ӱɡ�";
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
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "������")
		me->set_temp("apply/short", ({WHT"�����ɸ��� "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N�ó�һֻ���ƶ̵ѣ�����$n��\n", this_object(), me);
	return "����������鲻�ѣ����Ҫ���Ϊ�����˼ҷ��ǲ��ǣ�\n";    
}
