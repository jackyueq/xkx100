//bee.c

inherit NPC;

void create()
{
	set_name("�۷�", ({"bee"}) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 8);
	set("long", "����һֻ�۷䣬��æ�Ų��ۡ�\n");
	
	set("str", 40);
	set("dex", 50);
	set_temp("apply/attack", 33);
	set_temp("apply/armor", 20);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�۷������˷ɹ���������ͷ��ת��һȦ���з����ˡ�\n",
	}) );

	setup();
}

