//hudie.c

inherit NPC;

void create()
{
	set_name("����", ({"hudie"}) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 8);
	set("long", "����һֻ�ڻ����������ĺ������ƺ��������ء�\n");

	set("str", 20);
	set("dex", 50);
	set_temp("apply/attack", 33);
	set_temp("apply/armor", 20);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�����ɹ��������������������������������������ץס��ʱ�����ַ����ˡ�\n",
	 }) );

	setup();
}

