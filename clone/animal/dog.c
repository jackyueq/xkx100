// dog.c
// Last Modified by winder on Aug. 1 2002

// inherit NPC_TRAINEE;
inherit "/inherit/char/trainee";

void create()
{
	set_name("Ұ��", ({ "dog" }) );
	set("race", "����");
	set("age", 3);
	set("long", "һֻ�����������Ұ����\n");
	
	set("str", 32);
	set("dex", 36);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"Ұ���ñ�����������Ľš�\n",
		"Ұ������Ľű߰��������ģ����ֶ����ԡ�\n",
		"Ұ��������ҡ��ҡβ�͡�\n",
		"Ұ��������ץ��ץ�Լ��Ķ��䡣\n" }) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") )
	{
		set_leader(who);
		message("vision", name() + "���˵���������������\n", environment());
		return 1;
	}
}
