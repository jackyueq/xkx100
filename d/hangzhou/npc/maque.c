// maque.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("��ȸ", ({ "maque"}));
	set("race", "����");
	set("age", 3);
	set("long", "һֻС��ȸ������֦���������¡�\n");
	set("attitude", "peaceful");

	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		"��ȸ����ͷ�ϴ��ת���ַɻ����ϡ�\n",
		"��ȸ�����������˼�����\n",
	}) );

	setup();
}
