// ox.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("��ţ", ({ "mao niu","niu" }) );
	set("race", "����");
	set("age", 12);
	set("long", "һͷ��ŭ�Ĺ�ţ����������΢΢���Ž�⡣\n");

	set("str", 25);
	set("cor", 24);
	set("combat_exp",15000);

	set_temp("apply/attack", 15);
	set_temp("apply/armor", 25);
   
	set("chat_chance",5);
	set("chat_msg",({
		"��ţ���������۾�����ϸ�о����㡣\n",
		"��ţ������������������ȴû����һ��������\n",
	}));
	setup();
}

void die()
{
	message_vision("$Nŭ��һ����һͷײ��ɽ�ڣ������ˡ�\n",this_object());
	new(__DIR__"obj/niujiao")->move(environment(this_object()));
	destruct(this_object());
	return;
}
