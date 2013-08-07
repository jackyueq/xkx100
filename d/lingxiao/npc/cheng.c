// cheng.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

string ask_pai();
void create()
{
	set_name("����ѧ",({"cheng zixue","cheng"}));
	set("gender", "����");
	set("age", 40);
	set("long", "����ѧ��ѩɽ���������������������ڵ�ʦ�ܡ�\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("inquiry", ([
		"����"   : (:ask_pai:),
		"������" : (:ask_pai:),
		"������" : "Ҫ����ү�ӣ��ͱ���Ҫ�����ƲŽ���ȥ�����ƾ������⡣",
		"��ү��" : "Ҫ����ү�ӣ��ͱ���Ҫ�����ƲŽ���ȥ�����ƾ������⡣",
	]) );
	set("shen_type", 0);
	set("score", 50000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 180);
	set_skill("sword", 180);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("literate", 180);

	set_skill("xueshan-sword", 180);
	set_skill("bingxue-xinfa", 180);
	set_skill("snow-strike", 180);
	set_skill("snowstep", 180);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("������", 5, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}

string ask_pai()
{
	object me,ob;
	me=this_player(); 

	if(me->query("family/master_id")=="bai zizai")
	{
		command("say �����������Ϸ���Ҳ��ӡ�\n");
		message_vision(HIY"����ѧ�ó�һ�����ƣ�����$N \n\n"NOR,me);
		ob=new("/d/lingxiao/obj/yupai");
		ob->move(me);
		return "�������ߡ�\n";
	}
	if(me->query("family/master_id")=="bai wanjian")
	{
		command("say ���Ȼ�ǰ��򽣵ĵ��ӣ���ȥҲ�޷���");
		message_vision(HIY"����ѧ�ó�һ�����ƣ�����$N \n\n"NOR,me);
		ob=new("/d/lingxiao/obj/yupai");
		ob->move(me);
		return "�����˱����ر���������ʧ��\n";
	}
	command("say ����ʲô��ݣ�Ҳ��ȥ����ү�ӣ�");
	message_vision(HIY"����ѧת����ȥ��������$N��\n\n"NOR,me);

	return "�㻹����ȥŬ�������ɡ�\n";
}
void attempt_apprentice(object ob)
{
	command("say ���ǲ���ͽ�ģ���ȥ������Щͽ�ܰɡ�");
}

