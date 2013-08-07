// /d/shenlong/npc/smonkey.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("С����", ({ "monkey", "hou", "houzi" }) );
	set("race", "����");
	set("age", 2+random(3));
	set("long", "һֻ�����С���ӣ��۰Ͱ͵Ŀ����㣬�������Щ�Եġ�\n");
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����",  "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_skill("dodge", 10+random(20));

	set("combat_exp", 350+random(200));
	set_temp("apply/attack", 6+random(8));
	set_temp("apply/defense", 6+random(4));
	set_temp("apply/armor", 2);

	setup();

	set("chat_chance", 8);
	set("chat_msg", ({
		"һֻС���Ӻ�Ȼ�ܹ������������˸�Ҿ��\n",
		"һֻС����ߴߴ�������˹�����\n",
		"С���ӱı��������ܿ��ˡ�\n",
		"С����ҡҡβ���ܿ��ˡ�\n",
	}) );
}

int accept_object(object me, object obj)
{
	object ob;

	if ( obj->query("food_supply") && obj->value() >= 0 ) {
		command("jump " + me->query("id"));
		say("С���������±��"+(string)obj->query("name")+"�Եøɸɾ�����\n");

		remove_call_out("destroy_it");
		call_out("destroy_it", 1, obj);

		if( obj->query("id") != "banana" )
			return 1;

		message_vision("С��������$N���·���ʾ��$N��������\n", me);
		message("vision", me->name() + "����С����������ɽ������ҹյ�һ���ӱ㿴�����ˡ�\n", environment(me), ({me}));
		message("vision", "��һֻС�������˹�����\n", environment(me),({me}));
		write("������С������ɽ�����ţ���ת��ת�ظ������ʧ�˷���\n");
		write("�������ã�С���Ӱ������һƬ����ǰ��\n");
		write("�����ţ�С���ӱ���Ұ�������ˡ�\n");
		me->move("/d/quanzhou/milin");
		message("vision", me->name()+"����С�������˹�����\n", environment(me), ({me}) );
		return 1;
	} else {
		say("С���Ӱ�" + (string)obj->query("name") + "���˹�������Ū�˼��£��ƺ�������ʲô�á�\n");
		command("angry");
		command("kick " + me->query("id"));
		if (obj->query("money_id")) {
			ob = new(base_name(obj));
			ob->set_amount((int)obj->query_amount());
			ob->move(environment(me));
			say("С���Ӱ�"+(string)obj->query("name")+"�������ϡ�\n");}
		remove_call_out("drop_it");
		call_out("drop_it", 1);
	}

	return 1;
}

void drop_it()
{
	command("drop all");
}

void destroy_it(object obj)
{
	destruct(obj);
}

void init()
{
	object me = this_player();

	::init();

	if( interactive(me) && living(me) )
	{
		command("look " + me->query("id"));
		message_vision("С�������صض�$Nգ��գ�۾�����֨��֨��֨�����˼�����\n", me);
	}
}

