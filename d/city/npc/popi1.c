// popi1.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;

void create()
{
	set_name("�Ų���", ({"po pi","punk"}) );
	set("gender", "����" );
	set("title","��Ƥ");
	set("age", 20);
	set("long", "�����Ǹ���Ƥ�������������£������й䡣��\n");
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_skill("unarmed", 20);
	set("combat_exp", 2000);
	set("str", 25);
	set("per", 20);
	set("inquiry", ([
		"here" : "�����۾��Լ�������û��������æ���𣿣�",
	]) );
	set("chat_chance", 20);
	set("chat_msg", ({
"��Ƥ�������ֵ�˵�����ĳ��ϰ������費�Ƕ���������Ƿծ�ֲ��ǲ��ܻ��ˣ����Ұ����Ӻ��������\n",
"��Ƥ�����Լ����ֿ��˰��죬���������߶���ţ������ǹ��£����־�ץ��ʮ����\n",
"��ģ���Ƥ����������ţ��˶����������ˣ�����һûǮ�ˣ�������Ӱ���������ˣ�\n",
"��Ƥ˵����ȥȥ��һ��ȥ����ү�������أ�\n",
"��Ƥ�������㣬��֪������Щʲô��\n",
"��֪�������ܣ���ô�����������ͷ�е����\n",
		(:random_move:),
	}) );
	setup();
	carry_object(__DIR__"obj/poyi")->wear();
}

int accept_object(object me, object ob)
{
	int val;

	val = ob->value();
	if ( val < 5000  )
	{
		message_vision("�Ų��Ķ�$Nһ�����ۣ���ôһ��Ǯ����򷢴�ү�ң�\n", me);
		command( "kick " + me->query( "id" ) );
		return 0;
	}
	if (random(5) == 0)
		command( "whisper " + me->query("id") + " ��˵����в������䣬�Ǽ������أ�" );
	else 
	{
		command( "look " + me->query( "id" ) );
		command( "say �������ǹ��¶࣬������Ӳ��Ǯ�ģ����Ҿ������ˡ�");
	}
	return 1;
}

