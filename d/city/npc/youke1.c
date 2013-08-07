//Npc youke1.c

inherit NPC;


void create()
{
	set_name( "�ο�", ({"you ke","ke"}) );
	set( "gender", "����" );
	set( "age", 28 );
	set("attribute", "heroism");

	set_skill( "force", 20 );
	set_skill( "unarmed", 20 );
	set_skill( "dodge", 30 );

	set( "combat_exp", 2000 );

	set( "str", 25 );
	set( "per", 25);
	set( "con", 26);
	set( "inquiry", ([
		"����" : "���Ǵ����ˡ�\n",
		"����" : "�ҵļ����Ǵ������ι��ϱߵĴ���\n",
		"����" : "���ݹ����Ǹ������ĳ��а���\n",
	]) );
	set( "no_leave_yangzhou", 1);

	setup();
	set( "chat_chance", 10);
	set( "chat_msg", ({
		(:random_move:),
	}) );
	carry_object("/clone/cloth/male-cloth" )->wear();
}

