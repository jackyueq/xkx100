// xiangke.c

inherit NPC;
void create()
{
	set_name("���", ({ "xiang ke", "ke" }) );
	set("gender", (random(2)? "Ů��":"����") );
	set("age", random(40)+10);
	set("long", "һ����ɽ�������͡�\n");
	set("combat_exp", 5+random(5000));
	set("chat_chance", 70);
	set("chat_msg", ({
		(: random_move :),
		"���ָ����Χ�ľ�ɫ̾��������ѽ����\n",
		"��͵�������Ϊһ����ɽ����������������ѽ��\n",
		"��Ͷ���˵������Ҳ������ɽ�ģ�\n",
		"��Ͷ���˵�����㿴�������ѽ��\n",
		"��Ͷ���˵��������ı���������ˣ�\n",
	}) );

	set("attitude", "friendly");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

