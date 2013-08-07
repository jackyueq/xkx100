// tuying.c
// Last Modified by winder on Aug. 1 2002

// inherit NPC_TRAINEE;
inherit "/inherit/char/trainee";

void create()
{
	set_name("ͺӥ", ({ "eagle", "ying", "tuying" }) );
	set("race", "����");
	set("age", 15);
	set("long", "һֻ�����ڸ�ԭ�ϣ���ɫ��ͺӥ��һ�����������ë���׺���ª��\n");
	set("attitude", "aggressive");
	set("wildness", 9);
	set("msg_fail","$nһ������$N���ģ�$Næ������");
	set("msg_succ","$Nһ���֣�$n���������˼��³��");
	set("msg_trained","$n������������ͣ��$N�ļ���");
	set("auto_follow",1);

	set("str", 29);
	set("con", 40);
	set("dex", 45);
	set("int", 10);

	set("combat_exp", 12000);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 10);

	setup();

	set("chat_chance", 7);
	set("chat_msg", ({
		"����~~��~~��ͺӥ�������������İ��С�\n",
		"ͺӥͻȻ�Ӹ߿������ų��㸩��������ͣ�����㲻Զ����\n",
		"ͺӥ����ԥԥ���������ţ�̰�����۾��ݺݵض����㡣\n",
		"ͺӥ�����˼��³��\n",
	}) );
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		this_object()->query_lord() != ob &&
		random(ob->query_kar() + ob->query_per()) < 5)
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
