// maque.c

inherit NPC;

void create()
{
	set_name("��ȸ", ({ "ma que"}));
	set("race", "����");
	set("age", 3);
	set("long", "һֻС��ȸ����ʯ������Ϸ��¡�\n");
	set("attitude", "peaceful");

	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		"��ȸ�����������˼�����\n",
		"��ȸ�����ų��\n",
		"��ȸһ��ײ��ǽ�ϣ���������һ���ֵ��ڵ��ϡ�\n",
	}) );

	setup();
}
