// cheng.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_me();
int ask_stop();

void create()
{
	set_name("��ҩ��", ({ "cheng yaofa", "cheng" , "yaofa"}) );
	set("title", "����֪��" );
	set("gender", "����" );
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "�����ǳ�ҩ������������֪����\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	set("inquiry", ([
		"����": (: ask_me :),
		"����": (: ask_me :),
		"work": (: ask_me :),
		"Ч��": (: ask_me :),
		"quest": (: ask_me :),
		"���ݸ�": (: ask_me :),
		"����": (: ask_stop :),
		"stop": (: ask_stop :),
	]) );
	setup();
	carry_object(__DIR__"obj/mangpao")->wear();
	carry_object(__DIR__"obj/zizhuxiao")->wield();
	add_money("silver",30);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer", "answer");
}
int ask_me()
{
	object ob,me;
	me = this_player();
	if(me->query("officerlvl") < 1)
	{
		command("say ��λ"+ RANK_D->query_respect(me)
			+ "������Ϊ��͢Ч����������ǩѺ��������\n");
		return 1;
	}
	command("say ����Ϊ��͢��Ա�����ܰ׳Թ���ٺ»�����Ŭ������(work)����
����ÿ�ΰ���������ʵ�򱾸��㱨(finish)��");
	return 1;
}
int ask_stop()
{
	object ob,me;
	me = this_player();
	if (!(int)me->query_temp("bt/working"))
	{
		command("say ��λ"+ RANK_D->query_respect(me)
			+ "����Ը��Ϊ��͢Ч��������Ҳ����ǿ��\n");
		return 1;
	}
	command("say �����û��ץ���ﷸ��(answer yes��answer no)");
	me->set_temp("bt/stop",1);
	return 1;
}
int do_answer(string arg)
{
	object ob,me;
	me = this_player();
	if (!me->query_temp("bt/stop"))
	     return notify_fail("ʲô��\n");
	if (!arg || (arg !="yes"&&arg !="no"))
	{
		command("say ���������µ���˵ʲô����\n");
		return 1;
	}
	if (arg =="no")
	{			       //113
		command("say �ﷸ����ץ�����㻹Ҫ����ʲô��\n");
		return 1;
	}
	message_vision (BLU"��ҩ�����ɴ�ŭ���İ�����\n"NOR,me);
	command("say �󵨣�����Ϊ��͢��Ա��ʳ����ٺ»�������˲������ݹֱ������飡");
	command("say ���������������ʮ��塣");
	message_vision (BLU"�������ʱӵ�����������ƻ������۽�"+me->query("name")+"�����ڵء�\n"NOR,me);
	me->delete_temp("bt/stop");
	me->apply_condition("bt_stop", 10);
	return 1;
}

