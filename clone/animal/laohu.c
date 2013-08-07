// laohu.c �ϻ�
// Last Modified by winder on Aug. 1 2002

// inherit NPC_TRAINEE;
inherit "/inherit/char/trainee";

void create()
{
	set_name("�ϻ�", ({ "lao hu", "hu", "tiger" }) );
	set("race", "����");
	set("age", 25);
	set("long", "����һͷ�����׶�������ڵĴ󻢣�����ݺݵض����㣬������ʱ��ض������������˶��ɣ�\n");
	set("msg_fail", "$n��$N��������һ��");
	set("msg_succ", "$nһ�������$N�ɺɷ�����һ��������˰벽���ƺ���Щ����");
	set("msg_trained","$n�ͺ�����$N����ǰ��������");
	set("auto_follow",1);
	set("attitude", "aggressive");

	set("wildness", 12);
	set("ridable", 1);
	set("ability", 4);
	
	set("str", 40);	
	set("con", 40);
	set("dex", 40);	
	set("int", 10);

	set("combat_exp", 20000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  30);

	set_weight(150000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�ϻ���ǰצ�Ļ��ŵ��棬���кɺɷ�����������ʱ��Ҫ��������\n",
		"�ϻ�΢΢�����Դ���˫Ŀ������������ע�������һ��һ����\n",
		"�ϻ�ͻȻ�������������������˰�Ȧ���ƺ��ڹ۲���ʲô��\n",
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"\n�ϻ�ŭХһ����һ����������β��������һ�����˹�����\n",
		"\n�ϻ�ȫ��һ��һ������ȻԾ���գ��͵�����������\n",
	}) );
		
	setup();
}

void die()
{
	message_vision("\n$N����Һ���һ����ſ�ڵ��ϲ����ˡ�\n", this_object());
	::die();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && ob->query_weight() >= 50000)
	{
		if(!this_object()->query_lord(ob)) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
	}	
}

