// lamb.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("����", ({ "lamb", "yang", "huang yang" }) );
	set("race", "����");
	set("age", 11);
	set("long", "һֻҰ��������ͷ����س��Ųݡ�\n");

	set("str", 26);
	set("cor", 30);

	set("combat_exp", 800);

	set("chat_chance", 6);
	set("chat_msg", ({
		"������~~��~~�Ľ��˼�����\n"
	}) );

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ���~~��һ�������ˣ�\n", this_object());
	ob = new(__DIR__"obj/yangrou");
	ob->move(environment(this_object()));
	ob = new(__DIR__"obj/yangpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}

