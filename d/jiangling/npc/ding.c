//Edited by fandog, 01/31/2000

inherit NPC;
#include <ansi.h>

int ask_skill1();
int ask_skill2();
void create ()
{
	set_name("����", ({"ding dian","ding","dian"}));
	set("long", "
����������ף�ͷ��������ֱ���������������ò�������ֱ��ͬ��ɽ��
��Ұ�ˡ����������������ͣ����ù��д������������������ϡ����ϡ�
���ϣ����ǿ���޴��Ѫ�ۡ�\n");
	set("gender", "����");
	set("age", 30);
	set("combat_exp", 5000000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("per", 24);

	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("yanfly", 200);
	set_skill("shenzhao-jing", 300);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "shenzhao-jing");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "yanfly");
	set("chat_chance", 10);
	set("chat_msg", ({
"��������̾��һ��������̾Ϣ�У��������ˡ�����֮�⡣\n",
"������ǹ���һ˿΢Ц������Զ����¥ɴ������һ���ʻ���\n",
"�������������ô�����ǣ�������ģ��ѵ������ѵ������˲���\n",
"�����૵������������˲���Ҳ���������������\n",
}) );
	set("inquiry", ([
		"��˪��" : "������������Ȼ��ָ��ָ��������С¥�Ĵ��ڣ�ɶҲ��˵�ˡ�\n",
		"����"   : (: ask_skill1 :),
		"�ƾ�"   : (: ask_skill2 :),
	]));

	setup();
	carry_object("/d/jiangling/obj/qiuyi")->wear();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0;
	ob->add_temp("mark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (ob->query("id") == "green flower")
	{
		message_vision("����$N�����õ�����ָ��һЩ�书�����⡣\n",who);
		who->add_temp("mark/��", 1000);
		return 1;
	}
}

int ask_skill1()
{
	object ob = this_object();
	object who = this_player();
	
	if (!who->query_temp("mark/��")) return 0;
	if (!who->query_skill("shenzhao-jing",1)) return 0;
	if (who->query("can_perform/shenzhao-jing/wakeup")) return 0;
	if (who->query_skill("shenzhao-jing",1) < 100)
	{
		command("say ������վ������������ߣ���ѧѧ�ɡ�");
		return 1;
	}
	command("sign");
	command("say ��֪��ѧ�����վ��Ǹ��ǻ��ˡ�Ҳ�գ�����ȥ�ɡ�");
	tell_object(who,HIC"���������������˵�˼����˹��Ŀھ����㼱æ����һһ���¡�\n"NOR);
	tell_object(who,HIC "��ѧ���ˡ����ѡ���\n" NOR);
	who->set("can_perform/shenzhao-jing/wakeup",1);
	return 1;
}
int ask_skill2()
{
	object ob = this_object();
	object who = this_player();
	
	if (!who->query_temp("mark/��")) return 0;
	if (!who->query_skill("shenzhao-jing",1)) return 0;
	if (who->query("can_perform/shenzhao-jing/jingheal")) return 0;
	if (who->query_skill("shenzhao-jing",1) < 50)
	{
		command("say ������վ������������ߣ���ѧѧ�ɡ�");
		return 1;
	}
	command("sign");
	command("say ��֪��ѧ�����վ��Ǹ��ǻ��ˡ�Ҳ�գ�����ȥ�ɡ�");
	tell_object(who,HIC"���������������˵�˼����˹��Ŀھ����㼱æ����һһ���¡�\n"NOR);
	tell_object(who,HIC "��ѧ���ˡ��ƾ�����\n" NOR);
	who->set("can_perform/shenzhao-jing/jingheal",1);
	return 1;
}
