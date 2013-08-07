// Room: /d/huijiang/npc/sheep.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("����", ({ "sheep","yang" }) );
	set("race", "����");
	set("age", 22);
	set("long", "��ɫ����ë������������۲���ǧ��Ҫ������Ժ���\n");

	set("str", 13);
	set("cor", 24);
	set("combat_exp",5000);
	set_temp("apply/attack", 15);
	set_temp("apply/armor", 20);

	set("chat_chance",5);
	set("chat_msg", ({
		"�������һ��ݣ�̧ͷ�����Ŀ���ͷ��Ʈ���İ��ơ�\n",
		"����ڰ����ӣ������ȣ���ͷ����ײ����\n",
	}));

	setup();
}

void die()
{
	message_vision("$N�����£���֫�鴤һ�����ˡ�\n",this_object());
	new(__DIR__"obj/yangrou")->move(environment(this_object()));
	destruct(this_object());
	return;
}
