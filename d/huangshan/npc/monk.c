// monk.c

inherit NPC;
void create()
{
	set_name("�չ�", ({ "shaolin monk", "monk"}) );
	set("gender", "����" );
	set("age",random(10)+ 32);
	set("long", "���������³��⻯ի�ĺ��С�\n");
	set("combat_exp", random(10000)+10000);
	set("attitude", "friendly");
	set("chat_chance", 20);
	set("chat_msg", ({
		"�չ⳪�˸���ŵ������ʩ��������Ǯ�ɣ���\n",
	}) );
	set_skill("unarmed", 5+random(40));
	set_skill("dodge",40);
	set_skill("force",20);
	set("force",100);
	set("max_neili",100);
	create_family("������", 41, "����");
	setup();
	carry_object(CLOTH_DIR"sengpao")->wear();
	carry_object(__DIR__"obj/bowl");
}

int accept_object(object me, object obj)
{
	command("sigh");
	command("say �����ѹ�ѽ��\n");
	command("say ���ڵĲؾ�¥���Ƕ��飬�������ڶ��������𷣵������ʮ�꣡\n");
	command("thank " + me->query("id"));
	return 1;
}
