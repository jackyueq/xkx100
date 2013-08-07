// laohu.c ʨ��
// Last Modified by winder on Aug. 1 2002

// inherit NPC_TRAINEE;
inherit "/inherit/char/trainee";

void create()
{
	set_name("ʨ��", ({ "lion", "shi zi", "shi" }) );
	set("race", "����");
	set("age", 25);
	set("long", "һֻ��ë���׵���ʨ��צ���������������䡣\n");
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
		"ʨ�������߶�������������˰��Σ����кɺɵķ�����\n",
		"ʨ�ӳ�������һ����\n",
		"ʨ��ſ�ڵ��ϣ���ͷ���˶���ë��һ˫�۾����������㡣\n",
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
	if( interactive(ob = this_player()) && ob->query_weight() >= 50000) {
		if(!this_object()->query_lord(ob)) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
	}       

//      add_action("do_ride", "ride");
//      add_action("do_unride", "unride");
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object *inv;
	int i;

	inv = all_inventory(this_object());

	if (!id(arg)) return 0;

	if (!sizeof(inv)) return 0;

	printf(this_object()->query("long") + 
	COMBAT_D->eff_status_msg((int)this_object()->query("eff_qi")* 100 / (int)this_object()->query("max_qi")) + "\n" 
	+ "���������ţ�\n");
	for (i = 0; i < sizeof(inv); i++)
		printf("%s \n", inv[i]->short());
	return 1;
}
